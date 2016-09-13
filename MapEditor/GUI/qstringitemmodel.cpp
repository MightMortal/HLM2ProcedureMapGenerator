#include "qstringitemmodel.h"

QStringItemModel::QStringItemModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{

}

QStringItemModel::~QStringItemModel()
{
    rows.clear();
}

int QStringItemModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

QVariant QStringItemModel::data(const QModelIndex &index, int role) const
{
    if (rows.size() <= 0)
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    if (index.column() == 0)
        return rows.at(index.row());
    else
        return QVariant();
}

Qt::ItemFlags QStringItemModel::flags(const QModelIndex &index) const
{
    if (rows.size() <= 0)
        return 0;
    return QAbstractItemModel::flags(index);
}

QVariant QStringItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

QModelIndex QStringItemModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex QStringItemModel::parent(const QModelIndex &index) const
{
    return QModelIndex();
}

int QStringItemModel::rowCount(const QModelIndex &parent) const
{
    return rows.size();
}

void QStringItemModel::addObject(std::string value)
{
    rows.push_back(QString(value.c_str()));
}
