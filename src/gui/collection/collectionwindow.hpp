#ifndef COLLECTIONWINDOW_HPP
#define COLLECTIONWINDOW_HPP

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QtWidgets>
#include <QSlider>
#include "../../drawing/collections/drawcollection.hpp"
#include "algocollection.hpp"
#include "codecollection.hpp"
#include "../../drawing/collections/collection.hpp"
#include "../../backend/collections/collectionalgorithm.hpp"
#include "../playbacksettings.hpp"

namespace Ui {
class CollectionWindow;
}

class CollectionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CollectionWindow(QWidget *parent = 0);
    ~CollectionWindow();
    const static int triangleWidth = 50;
    const static int buttonWidth = 150;
    const static int buttonHeight = 40;
    Collection* getCollection();
    static QPair<int, unsigned> playback;
    static QMutex playbackMutex;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void pushButtonReturn_clicked();
    void enableRightDockWindow();
    void animateRightDockWindow();
    void changeRightDockWindow();
    void setCollection(Collection *c);
    void startAlgorithmPlayback(Algorithm* algo);
    void on_actionSave_As_Image_triggered();
    void on_actionQuit_triggered();
    void on_actionCombinear_triggered();
    void on_actionDarkeum_triggered();
    void on_actionDiffnes_triggered();
    void on_actionIntegrid_triggered();
    void on_actionMedize_triggered();
    void on_actionPlay_triggered();
    void on_actionPause_triggered();
    void on_actionStop_triggered();
    void plus_clicked();
    void minus_clicked();
    void changePlaybackSpeed(int);
    void playbackFinished(bool);
    void on_actionInstructions_triggered();
    void on_actionAbout_Djiki_triggered();

private:
    void createDockWindows();
    void createTopDockWindow();
    void createRightDockWindow();
    void setAlgoCollectionAtRightDockWindow();
    void setCodeCollectionAtRightDockWindow();
    void enableThings();
    void disableThings();
    bool isChild(const QString &str);
    void deleteChildren();
    void animationSetup();
    void toolBarSetup();
    void executeAlgorithm(CollectionAlgorithm* algorithmInstance);
    void clearStylesheets();
    void setTheme(QFile *file);

    Ui::CollectionWindow *ui;
    DrawCollection *drawCollection;
    AlgoCollection *algoCollection;
    CodeCollection *codeCollection;
    Collection *currentCollection;
    CollectionAlgorithm* algorithmInstance;


    QDockWidget *dockRight;
    QDockWidget *dockTop;
    QPushButton *pushButtonReturn;
    QSequentialAnimationGroup *group;
    QPropertyAnimation *hideAlgo;
    QPropertyAnimation *showCode;
    QSequentialAnimationGroup *group2;
    QPropertyAnimation *hideCode;
    QPropertyAnimation *showAlgo;
    QSlider *slider;
    QPushButton *plus;
    QPushButton *minus;
    QString name;
};

#endif // COLLECTIONWINDOW_HPP
