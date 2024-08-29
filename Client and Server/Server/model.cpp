#include "model.h"
#include "data.h"
#include <QBrush>

Model::Model()
{}

Model *Model::getInstance()
{
    static Model *instance = nullptr;
    if(!instance)
    {
        instance = new Model;
    }
    return instance;
}

Model::~Model()
{
    qDeleteAll(m_dataList);
}

int Model::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_dataList.size();
}

int Model::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_columnCount;
}

QVariant Model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    int col = index.column();
    int row = index.row();

    if(role == Qt::DisplayRole || role == Qt::EditRole){
        switch(col){
        case 0:
            //Pallet Number
            return m_dataList[row]->getPalletNumber();
            break;
        case 1:
            //Container Type
            return m_dataList[row]->getContainerType();
            break;
        case 2:
            //Container Code
            return m_dataList[row]->getContainerCode();
            break;
        case 3:
            //Height
            return m_dataList[row]->getHeight();
            break;
        case 4:
            //Breadth / Diammeter
            return m_dataList[row]->getBreadthDiameter();
            break;
        case 5:
            //Length
            return m_dataList[row]->getLength();
            break;
        case 6:
            //Weight
            return m_dataList[row]->getWeight();
            break;
        default:
            return QVariant();
        }
    }

    if(role == Qt::BackgroundRole){
        if(row % 2 == 0){
            return QBrush(Qt::lightGray);
        }
    }

    return QVariant();
}


QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole){
        return QVariant();
    }

    if(orientation == Qt::Vertical){
        return QVariant(section + 1);
    }

    switch (section)
    {
    case 0:
        return QString("Pallet");
        break;
    case 1:
        return QString("Container");
        break;
    case 2:
        return QString("Code");
        break;
    case 3:
        return QString("Height");
        break;
    case 4:
        return QString("Breadth/Diameter");
        break;
    case 5:
        return QString("Length");
        break;
    case 6:
        return QString("Weight");
        break;
    default:
        return QVariant();
    }
    return QVariant();
}

void Model::addData(Data *data)
{
    int row = m_dataList.size();
    beginInsertRows(QModelIndex(), row, row);
    m_dataList.append(data);
    endInsertRows();
}

void Model::clear()
{
    int rowCount = m_dataList.size();
    if(rowCount > 0){
        beginRemoveRows(QModelIndex(), 0, rowCount - 1);
        qDeleteAll(m_dataList);
        m_dataList.clear();
        endRemoveRows();
    }
}
