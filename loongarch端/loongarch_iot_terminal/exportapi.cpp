#include "exportapi.h"

exportapi::exportapi()
{

}

void exportapi::exportTxt(QString title, QTableWidget *table)
{
    //Qstring转string
    QString file = title + ".txt";
    string filestd = file.toStdString();

    QString str = "";
    string strstd = "";
    QTableWidgetItem *cellItem;

    ofstream out(filestd);
    if(out.is_open())
    {
        //内容添加至文件
        for (int i = 0; i < table->rowCount(); i++) //逐行处理
        {
            for (int j = 0; j < table->columnCount(); j++)
            {
                cellItem = table->item(i,j); //获取单元格的item
                str += cellItem->text()+"|";         //字符串连接
            }
            str += '\n';
        }

        strstd = str.toStdString();
        out << strstd;

        //关闭文件
        out.close();
    }
}
