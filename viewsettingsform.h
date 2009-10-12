#ifndef VIEWSETTINGSFORM_H
#define VIEWSETTINGSFORM_H

#include <QtGui/QDialog>

namespace Ui {
    class ViewSettingsForm;
}

class ViewSettingsForm : public QDialog {
    Q_OBJECT
public:
    ViewSettingsForm(QWidget *parent = 0);
    ~ViewSettingsForm();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ViewSettingsForm *m_ui;
};

#endif // VIEWSETTINGSFORM_H
