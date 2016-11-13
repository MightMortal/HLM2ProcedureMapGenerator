#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../common.h"

#include <QMainWindow>

#include "qstringitemmodel.h"
#include "../LevelDescriptors/PlayMap.h"
#include "../LevelDescriptors/WallMap.h"
#include "../LevelDescriptors/TileMap.h"
#include "../Assets/ObjectManager.h"
#include "../LevelDescriptors/Level.h"

namespace Ui {
class MainWindow;
}

class AssetDescriptor;

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(ObjectManager &om, QWidget *parent = 0);
    ~MainWindow();

    void setAssetDescriptors(std::vector<AssetDescriptor *> descriptors);
    std::vector<AssetDescriptor *> getAssetDescriptors();
    void renderLevel(Level &level);
    void renderSprite(std::string image, int x, int y, int tx, int ty, int w, int h, float angle, bool shift = false);
    void fillColor(int x, int y, int w, int h, unsigned int color);
//    void renderObjects(vector<PlayObject> &objects);
//    void renderObjects(vector<EditorObject> &objects);
    template<typename T>
    void renderObjects(vector<T> &objects);

    void renderWalls(vector<EditorWall> &walls);
    void renderTiles(vector<EditorTile> &tiles);

public slots:
    void cellChanged(int row, int column);
    void on_loadButton_clicked(bool checked);
    void on_saveButton_clicked(bool checked);
    void on_propertyEditWidget_cellChanged(int row, int column);
    void on_descriptorsListView_doubleClicked(const QModelIndex &index);

private:
    ObjectManager &om;
    const int SCALE = 1;
    const int LEVEL_VIEW_WIDTH = 1088;
    const int LEVEL_VIEW_HEIGHT = 768;

    QStringItemModel *assetDescriporsListModel;
    Ui::MainWindow *ui;
    double renderScale;
};

#endif // MAINWINDOW_H
