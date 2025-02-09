#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QMainWindow window;
  window.resize(400, 100);
  QWidget* centralWidget = new QWidget(&window);
  QVBoxLayout* layout = new QVBoxLayout(centralWidget);

  QLabel* label = new QLabel("Counter: 0", centralWidget);
  QPushButton* button = new QPushButton("Increment", centralWidget);
  button->setStyleSheet("background-color: orange;");

  int counter = 0;
  QObject::connect(button, &QPushButton::clicked, [label, centralWidget, &counter]() {
    counter++;
    label->setText("Counter: " + QString::number(counter));

    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int b = QRandomGenerator::global()->bounded(256);

    QString color = QString("background-color: rgb(%1, %2, %3);").arg(r).arg(g).arg(b);
    centralWidget->setStyleSheet(color);
  });

  layout->addWidget(label);
  layout->addWidget(button);

  window.setCentralWidget(centralWidget);
  window.show();

  return app.exec();
}