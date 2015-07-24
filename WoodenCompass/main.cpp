#include <iostream>
#include <stdexcept>

#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QPushButton>

using namespace std;

int main(int argc, char **argv)
{
	QApplication app{argc, argv};
	try
	{
		cout << "Wooden Compass" << endl;

		QPushButton button{"Test button"};
		QObject::connect(&button, &QPushButton::clicked, &app, &QApplication::quit);
		button.show();

		return app.exec();
	}
	catch (exception const& e)
	{
		QMessageBox::critical(nullptr, "Error", e.what());
	}
}
