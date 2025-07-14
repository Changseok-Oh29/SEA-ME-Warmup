#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Contactlist.h"
#include <QMainWindow>
#include "ui_mainwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    ContactList contacts;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAdd();
    void onRemove();
    void onSearch();
    void onSave();
    void onLoad();
};


#endif // MAINWINDOW_H
