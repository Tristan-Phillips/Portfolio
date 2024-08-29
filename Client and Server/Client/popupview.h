#ifndef POPUPVIEW_H
#define POPUPVIEW_H

/* Used to display the about and help popup windows
 * without having to create a seperate class for each to display
 */

//Includes
#include <QDialog>

//Forward Declerations
class QTextEdit;
class QPushButton;

class PopupView : public QDialog
{
public:
    PopupView();
    ~PopupView();
    //Displays the file located in the path of fileName
        void display(QString fileName);
private:
    QTextEdit *m_txtEdit;
    QPushButton *m_btnClose;
};

#endif // POPUPVIEW_H
