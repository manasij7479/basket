#include <QDockWidget>
#include <QGraphicsView>
#include <QTreeView>
#include <QModelIndex>
#include <QVBoxLayout>

#include <KAction>
#include <KStandardAction>
#include <KLocale>
#include <KApplication>
#include <KActionCollection>
#include <KDebug>
#include <KLineEdit>

#include "basketmainwindow.h"
#include "baskettreeview.h"
#include "basketviewcontainer.h"

BasketMainWindow::BasketMainWindow( QWidget *parent ) : KXmlGuiWindow( parent ) {
	QDockWidget *treeViewDock = new QDockWidget( i18n( "Tree" ) );
	treeViewDock->setObjectName( "treeViewDock" );
	treeViewDock->setAllowedAreas( Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea );
	BasketTreeView *treeView = new BasketTreeView();
	treeViewDock->setWidget( treeView );
	addDockWidget( Qt::LeftDockWidgetArea, treeViewDock );
	connect( treeView, SIGNAL(clicked( const QModelIndex& )), this, SLOT(update0(const QModelIndex&)) );
	treeViewDock->toggleViewAction()->setText( i18n( "Tree" ) );
	treeViewDock->toggleViewAction()->setShortcut( Qt::Key_F9 );
	actionCollection()->addAction( "tree_view", treeViewDock->toggleViewAction() );

	BasketViewContainer *view = new BasketViewContainer();
	setCentralWidget( view );
	setupGUI();

}

BasketMainWindow::~BasketMainWindow() {
}

void BasketMainWindow::update0( const QModelIndex& index ) {
	kDebug() << "clicked: " << index.row() << " : " << index.column() << endl;
}