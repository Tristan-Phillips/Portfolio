//Local Includes
#include "popupview.h"

//External Includes
#include <QMessageBox>
#include <QTextEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QVBoxLayout>
//Unnesasary includes
#include <QDate>
#include <QHostAddress>

PopupView::PopupView()
    : m_txtEdit{new QTextEdit},
      m_btnClose{new QPushButton(tr("Close"))}
{
    //Pre-set
        m_txtEdit->setReadOnly(true);
    //Layout
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(m_txtEdit);
        layout->addWidget(m_btnClose);
        setLayout(layout);
    //Connections
        connect(m_btnClose, &QPushButton::clicked, this, &QDialog::close);
}

PopupView::~PopupView()
{
    deleteLater();
}

void PopupView::display(QString fileName)
{
    /*Reads file and appends it to the text edit*/
        QFile file(fileName);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            QString readLines;
            while(!in.atEnd())
            {
                /* Reads each line and appends it to the text edit
                * with modifications made to certain key words*/

                    QString line = in.readLine();
                    if(line.contains("[todayDate]"))
                    {
                        QDate date = QDate::currentDate();
                        line.replace("[todayDate]", date.toString("dd/MM/yyyy"));
                    }else if(line.contains("[qtversion]")){
                        line.replace("[qtversion]", qVersion());
                    }else if(line.contains("[platform]")){
                        line.replace("[platform]", qVersion());
                    }else if(line.contains("[localIp]")){
                        //Idk thought it would be funny to add this
                            line.replace("[localIp]", QHostAddress(QHostAddress::LocalHost).toString());
                    }
                    readLines.append(line);
            }
            //To show the HTML and inline CSS formatting
                m_txtEdit->setHtml(readLines);

            //Alter the appearance of the popup window
                m_txtEdit->setFixedHeight(m_txtEdit->height());
                this->resize(sizeHint());
                m_txtEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

            file.close();
            this->show();
        }else{
            QMessageBox::warning(this, tr("Warning"), tr("Could not open file"));
        }
}