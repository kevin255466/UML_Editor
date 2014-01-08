#ifndef UML_KEDITOR_H
#define UML_KEDITOR_H

#include <QtGui/QMainWindow>
#include "ui_uml_keditor.h"
#include "Scene.h"



class UML_KEditor : public QMainWindow{

	Q_OBJECT;
public:

	UML_KEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~UML_KEditor();
	void connect();
	void initializeEditor();

public slots:
	void onUseCaseButtonClicked();
	void onClassButtonClicked();
	void onSelectButtonClicked();
	void onAssociationClicked();
	void onGenerationClicked();
	void onCompositiooClicked();
	void onChangeNameClicked();
	void onGroupItemClicked();
	void onUnGroupItemClicked();

private:
	Ui::UML_KEditorClass ui;
};

#endif  UML_KEDITOR_H
