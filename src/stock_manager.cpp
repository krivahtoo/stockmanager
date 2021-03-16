#include "stock_manager.h"
#include "ui_stock_manager.h"

stock_manager::stock_manager(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::stock_manager)
{
    m_ui->setupUi(this);
}

stock_manager::~stock_manager() = default;
