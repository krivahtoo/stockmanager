#ifndef STOCK_MANAGER_H
#define STOCK_MANAGER_H

#include <QMainWindow>
#include <QScopedPointer>

namespace Ui {
class stock_manager;
}

class stock_manager : public QMainWindow
{
    Q_OBJECT

public:
    explicit stock_manager(QWidget *parent = nullptr);
    ~stock_manager() override;

private:
    QScopedPointer<Ui::stock_manager> m_ui;
};

#endif // STOCK_MANAGER_H
