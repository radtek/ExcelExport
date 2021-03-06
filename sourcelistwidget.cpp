#include "sourcelistwidget.h"
#include "DetailXmlWidget.h"
#include "DetailExcelWidget.h"
#include "Global.h"

SourceListWidget::SourceListWidget()
{
    connect(this, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(itemDoubleClicked(QListWidgetItem*)));
}

SourceListWidget::~SourceListWidget()
{
}

QStringList SourceListWidget::getTableList()
{
    int count = this->count();
    QStringList list;
    for(int i=0; i<count; i++){
        auto item = this->item(i);
        list<<item->text();
    }
    return list;
}

void SourceListWidget::itemDoubleClicked(QListWidgetItem * item)
{

    QString name = item->data(Qt::UserRole).toString();
    if (name.section("/", -1).section(".", -1).compare("xlsx", Qt::CaseInsensitive) == 0){
        g_DetailExcelWidget->setVisible(true);
        g_DetailXmlWidget->setVisible(false);
        auto widget_ = dynamic_cast<DetailExcelWidget*>(g_DetailExcelWidget);
        widget_->getXlsxData(name);
    }
    else if (name.section("/", -1).section(".", -1).compare("xml", Qt::CaseInsensitive) == 0){
        g_DetailExcelWidget->setVisible(false);
        g_DetailXmlWidget->setVisible(true);
        auto widget_ = dynamic_cast<DetailXmlWidget*>(g_DetailXmlWidget);
        widget_->getXMLData(name);
    }
}
