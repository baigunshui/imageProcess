#ifndef MORPHINGSELECT_H
#define MORPHINGSELECT_H

#include <QMainWindow>

#include <QMessageBox>
#include <QFileDialog>
#include <QTime>
#include <QDir>
#include <QFile>

namespace Ui {
class MorphingSelect;
}

class MorphingSelect : public QMainWindow
{
    Q_OBJECT

public:
    explicit MorphingSelect(QWidget *parent = nullptr);
    ~MorphingSelect();

    QString getCurrentDirPath_2() const;
    void setCurrentDirPath_2(const QString &value);

    QString getCurrentDirPath_1() const;
    void setCurrentDirPath_1(const QString &value);

private slots:
    void on_backButton_clicked();
    void on_sureButton_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

signals:
    void sendsignal();

private:
    QString currentDirPath_1;
    QString currentDirPath_2;
    Ui::MorphingSelect *ui;
};

#endif // MORPHINGSELECT_H
