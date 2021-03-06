#ifndef EXCELEXPORT_H
#define EXCELEXPORT_H

#include <QMainWindow>
#include "DetailXmlWidget.h"
#include "SourceListWidget.h"
#include "DetailExcelWidget.h"
#include "QLayout"
#include "fielddialog.h"
#include "batchgeneratedialog.h"
#include "filterdialog.h"

namespace Ui {
class ExcelExport;
}

class ExcelExport : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExcelExport(QWidget *parent = 0);
    ~ExcelExport();


private slots:
    void on_actionOpen_triggered();
    void on_actionGenerateDir_triggered();
    void on_OpenButton_clicked();
    void on_GenerationButton_clicked();
    void on_actionField_triggered();
    void on_actionBatchGenerator_triggered();
    void on_actionFilterSetting_triggered();
    void on_checkButton_clicked();
private:
    Ui::ExcelExport *ui;
    DetailXmlWidget* xmlwidget_;
    DetailExcelWidget* excelwidget_;
    SourceListWidget* listWidget;
    QGridLayout* gridLayout;
    FieldDialog* fieldDialog;
    BatchGenerateDialog* batchGenerateDialog;
    FilterDialog* filterDialog;
};

#endif // EXCELEXPORT_H
