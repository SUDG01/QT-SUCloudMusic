#include "SUmusic.h"
#include "MessgeBox.h"

#include <QApplication>
#include <iostream>
#include <filesystem>
#include <QWidget>
#include <QIcon>
namespace fs = std::filesystem;



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MessgeBox msgbox;
    SUmusic w;
    a.setWindowIcon(QIcon(":/icon/4SUmusic/rainy_headicon.png"));
    std::string folderName = "Music";
    try{
        if(fs::exists(folderName)){
            w.show();
            return a.exec();
        }else if(fs::create_directory(folderName)){
            w.show();
            return a.exec();
        }else{
            msgbox.show();
            return a.exec();
        }

    }catch (const fs::filesystem_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
