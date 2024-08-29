#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QVariant>

/*
    This class is the model for the table view in the GUI.
*/

class Data;

class Model : public QAbstractTableModel
{
public:
    static Model *getInstance();
    ~Model();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    void addData(Data *data);
    void clear();

private:
    Model();
    QList <Data*> m_dataList;
    int m_columnCount = 7;
};

#endif // MODEL_H
