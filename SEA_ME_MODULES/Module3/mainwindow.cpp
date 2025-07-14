#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAdd);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::onRemove);
    connect(ui->searchButton, &QPushButton::clicked, this, &MainWindow::onSearch);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSave);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoad);
}

void MainWindow::onAdd() {
    Contact c(ui->nameInput->text(), ui->phoneInput->text(), ui->emailInput->text());
    contacts.add(c);
    ui->contactList->addItem(c.getName() + " | " + c.getPhone() + " | " + c.getEmail());
}

void MainWindow::onRemove() {
    QListWidgetItem* selected = ui->contactList->currentItem();
    if (selected) {
        QString line = selected->text();
        QStringList parts = line.split(" | ");
        if (parts.size() == 3) {
            Contact c(parts[0], parts[1], parts[2]);
            bool removed = contacts.remove(c);
            if (removed) {
                delete selected;
                contacts.saveToFile("contacts.txt");
                return;
            }
        }
    }

    QString keyword = ui->nameInput->text().trimmed();
    if (keyword.isEmpty()) {
        QMessageBox::warning(this, "Input requested", "Write name that you want to erase or click contact");
        return;
    }

    QVector<Contact> all = contacts.getAll();
    bool found = false;

    for (const Contact& c : all) {
        if (c.getName().trimmed().compare(keyword, Qt::CaseInsensitive) == 0) {
            contacts.remove(c);
            found = true;
            break;
        }
    }

    if (!found) {
        QMessageBox::warning(this, "Cannot erase", "Cannot find the name in contact.");
    }
    else {
        contacts.saveToFile("contacts.txt");
        onLoad();
    }
}

void MainWindow::onSearch() {
    QString keyword = ui->nameInput->text();
    ui->contactList->clear();
    for (const auto& c : contacts.searchByName(keyword)) {
        ui->contactList->addItem(c.getName() + " | " + c.getPhone() + " | " + c.getEmail());
    }
}

void MainWindow::onSave() {
    contacts.saveToFile("contacts.txt");
}

void MainWindow::onLoad() {
    contacts.loadFromFile("contacts.txt");
    ui->contactList->clear();
    for (const auto& c : contacts.getAll()) {
        ui->contactList->addItem(c.getName() + " | " + c.getPhone() + " | " + c.getEmail());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
