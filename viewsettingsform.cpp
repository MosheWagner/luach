#include "viewsettingsform.h"
#include "ui_viewsettingsform.h"

ViewSettingsForm::ViewSettingsForm(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::ViewSettingsForm)
{
    m_ui->setupUi(this);
}

ViewSettingsForm::~ViewSettingsForm()
{
    delete m_ui;
}

void ViewSettingsForm::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
