#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qstringitemmodel.h"
#include "../Assets/Sprite.h"
#include "../Assets/Atlas.h"
#include <vector>
#include <QGraphicsPixmapItem>
#include <cstdio>
#include <QtWidgets/QFileDialog>
#include <ctime>
#include "../../Generator/Interior/Building.h"

Level generateLevel() {
    srand(time(0));
    int width = LEVEL_MAX_WIDTH * (2.7 / 3.0);
    int height = (int) (LEVEL_MAX_HEIGHT * (2.5 / 3.0));
    Building building(Rectangle(Point(0, 0), Point(width, height)));
    building.generateDoors();
    building.generateWindows();
    building.generateFurniture();
    building.placeWeapon();
    building.placeEnemy();
//    for (auto it = building.rooms->begin(); it != building.rooms->end(); ++it) {
//        cout << "Type: " << it->type << endl;
//        cout << "LeftUpper: (" << it->rect.first.x << ", " << it->rect.first.y << "), RightBottom: ("
//             << it->rect.second.x << ", " << it->rect.second.y << ")" << endl;
//    }
//    for (auto it = building.walls.begin(); it != building.walls.end(); ++it) {
//        cout << "Wall from (" << it->first.x << ", " << it->first.y << ") to ("
//             << it->second.x << ", " << it->second.y << ")" << endl;
//    }
    Level level;
    level.wallMaps.push_back(building.generateWallMap());
    level.tileMaps.push_back(building.generateTileMap());
    level.objectMaps.push_back(building.generateObjectMap());
    level.playMaps.push_back(building.generatePlayMap());
    return level;
}

MainWindow::MainWindow(ObjectManager &om, QWidget *parent)
    :
    om(om),
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    renderScale(2.0) {
    ui->setupUi(this);

    QStringItemModel *stringItemModel = new QStringItemModel(QString("asdf"));
    ui->descriptorsListView->setModel(stringItemModel);

    ui->propertyEditWidget->setColumnCount(2);
    ui->propertyEditWidget->setRowCount(0);

    QGraphicsScene *scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MainWindow::renderSprite(std::string filename,
                              int x,
                              int y,
                              int tx,
                              int ty,
                              int w,
                              int h,
                              float angle,
                              bool shift) {
    QPixmap texturePixmap;
    texturePixmap.load(QString(filename.c_str()));
    QPixmap pixmap;
    if (shift) {
        QTransform transform;
        transform.rotate(-angle);
        pixmap = texturePixmap.copy(tx, ty, w, h).transformed(transform);
    } else
        pixmap = texturePixmap.copy(tx, ty, w, h);

    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
    if (shift)
        item->setOffset(x - pixmap.width() / 2.0, y - pixmap.height() / 2.0);
    else
        item->setOffset(x, y);
    item->setScale(SCALE);
    ui->graphicsView->scene()->addItem(item);
}

void MainWindow::fillColor(int x, int y, int w, int h, unsigned int color) {
    int r = (color >> 16) & 0xFF, g = (color >> 8) & 0xFF, b = (color) & 0xFF;
    QPixmap pixmap(w * SCALE, h * SCALE);
    pixmap.fill(QColor(r, g, b));
    QGraphicsPixmapItem *item = new QGraphicsPixmapItem(pixmap);
    item->setOffset(x * SCALE, y * SCALE);
    ui->graphicsView->scene()->addItem(item);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setAssetDescriptors(vector<AssetDescriptor *> descriptors) {
    // TODO: Implement
}

vector<AssetDescriptor *> MainWindow::getAssetDescriptors() {
    // TODO: Implement
}

void MainWindow::renderLevel(Level &level) {
    ui->graphicsView->scene()->clear();
    renderTiles(level.tileMaps.begin()->tiles);
    renderWalls(level.wallMaps.begin()->walls);
    renderObjects(level.objectMaps.begin()->objects);
}

void MainWindow::cellChanged(int row, int column) {
//    printf("Cell %d/%d changed\n", row, column);
}

void MainWindow::on_loadButton_clicked(bool checked) {
//    QString dir = QFileDialog::getExistingDirectory(this,
//                                                    "Open level directory",
//                                                    QString(),
//                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
//    Level level(dir.toStdString());
//    fillColor(0, 0, LEVEL_VIEW_WIDTH, LEVEL_VIEW_HEIGHT, 0xFFFFFFFF);
    Level level = generateLevel();
    level.save(".");
    renderLevel(level);
}

void MainWindow::on_saveButton_clicked(bool checked) {

}

void MainWindow::on_propertyEditWidget_cellChanged(int row, int column) {

}

void MainWindow::on_descriptorsListView_doubleClicked(const QModelIndex &index) {

}

template<typename T>
void MainWindow::renderObjects(vector<T> &objects) {
    int tx, ty, w, h;
    for (auto editorObject : objects) {
        Sprite *sprite = om.get(editorObject.id).second;
        if (sprite == nullptr) {
//            cout << "Object <" << editorObject.id << "> doesn't have sprite" << endl;
            sprite = om.getSprite(editorObject.spriteId);
        }
        if (sprite != nullptr) {
            string spriteName = sprite->SpritePath().substr(sprite->SpritePath().find_last_of('/') + 1);
            string atlasPath = SpritesIndex::getSpritePath(spriteName);
            string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
            Atlas atlas(atlasPath);
            AtlasSprite *as = atlas.sprites[spriteName];
            tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
            ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
            w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
            h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
            renderSprite(spritePath + ".png", editorObject.x, editorObject.y, tx, ty, w, h, editorObject.angle, true);
        }
    }
}

void MainWindow::renderWalls(vector<EditorWall> &walls) {
    int tx, ty, w, h;
    for (auto editorWall : walls) {
        Wall *wall = om.getWall(editorWall.id);
        string spriteName = wall->getName().substr(wall->getName().find_last_of('/') + 1);
        string atlasPath = SpritesIndex::getSpritePath(spriteName);
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[spriteName]->frames.at(0)->getOffsetX();
        ty = atlas.sprites[spriteName]->frames.at(0)->getOffsetY();
        w = atlas.sprites[spriteName]->frames.at(0)->getWidth();
        h = atlas.sprites[spriteName]->frames.at(0)->getHeight();
        renderSprite(spritePath + ".png", editorWall.x, editorWall.y, tx, ty, w, h, 0);
    }
}

void MainWindow::renderTiles(vector<EditorTile> &tiles) {
    int tx, ty, w, h;
    for (auto editorTile : tiles) {
        Tile *tile = om.getTile(editorTile.id);
        string atlasPath = SpritesIndex::getSpritePath(tile->getName());
        string spritePath = atlasPath.substr(0, atlasPath.size() - 5);
        Atlas atlas(atlasPath);
        tx = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetX() + editorTile.textureX;
        ty = atlas.sprites[tile->getName()]->frames.at(0)->getOffsetY() + editorTile.textureY;
        if (editorTile.id == 10)
            w = h = 8;
        else
            w = h = 16;
        renderSprite(spritePath + ".png", editorTile.x, editorTile.y, tx, ty, w, h, 0);
    }
}
