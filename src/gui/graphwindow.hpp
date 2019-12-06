#ifndef GRAPHWINDOW_HPP
#define GRAPHWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphWindow(QWidget *parent = 0);
    ~GraphWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GraphWindow *ui;
};

#endif // GRAPHWINDOW_HPP
