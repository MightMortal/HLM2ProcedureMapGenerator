#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../../common.h"

#include <QMainWindow>

#include "qstringitemmodel.h"

namespace Ui
{
class MainWindow;
}

class AssetDescriptor;

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setAssetDescriptors(vector<AssetDescriptor> descriptors);
    vector<AssetDescriptor> getAssetDescriptors();
    void renderLevel();
    void renderSprite(std::string image, int x, int y, int tx, int ty, int w, int h);
    void fillColor(int x, int y, int w, int h, unsigned int color);
public slots:
    void cellChanged(int row, int column);

private:
    const int SCALE = 2;

    QStringItemModel *assetDescriporsListModel;
    Ui::MainWindow *ui;
    double renderScale;
};

#endif // MAINWINDOW_H
