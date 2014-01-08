#include "uml_keditor.h"

UML_KEditor::UML_KEditor(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	initializeEditor();
	Scene::SceneGetInstance()->mode = new SelectMode( );
	connect();
}

UML_KEditor::~UML_KEditor()
{

}

void UML_KEditor::initializeEditor(){

	ui.setupUi(this);
	Scene::SceneGetInstance()->setSceneRect(ui.graphicsView->rect());
	ui.graphicsView->setScene( Scene::SceneGetInstance() );
}

void UML_KEditor::connect(){

	
	QObject::connect( ui.actionUseCase,			 SIGNAL(triggered()), this, SLOT(onUseCaseButtonClicked()));
	QObject::connect( ui.actionClass,			 SIGNAL(triggered()), this, SLOT(onClassButtonClicked()));
	QObject::connect( ui.actionChoose,			 SIGNAL(triggered()), this, SLOT(onSelectButtonClicked()));
	QObject::connect( ui.actionAssociation,		 SIGNAL(triggered()), this, SLOT(onAssociationClicked()));
	QObject::connect( ui.actionGeneration,       SIGNAL(triggered()), this, SLOT(onGenerationClicked()));
	QObject::connect( ui.actionComposition,      SIGNAL(triggered()), this, SLOT(onCompositiooClicked()));
	QObject::connect( ui.actionText,			 SIGNAL(triggered()), this, SLOT(onChangeNameClicked()));
	QObject::connect( ui.actionGroup,			 SIGNAL(triggered()), this, SLOT(onGroupItemClicked()));
	QObject::connect( ui.actionUnGroup,			 SIGNAL(triggered()), this, SLOT(onUnGroupItemClicked()));
}

void UML_KEditor::onUseCaseButtonClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(true);
		ui.actionClass->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new CreateMode( Item::UseCase );
}

void UML_KEditor::onClassButtonClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(true);
		ui.actionAssociation->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new CreateMode(Item::Class );
}


void UML_KEditor::onSelectButtonClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(true);
		ui.actionAssociation->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new SelectMode();
}

void UML_KEditor::onAssociationClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(true);
		ui.actionComposition->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new LineMode( Line::AssociationLine);
}

void UML_KEditor::onGenerationClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionGeneration->setChecked(true);
		ui.actionComposition->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new LineMode( Line::GenerationLine);
}

void UML_KEditor::onCompositiooClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionComposition->setChecked(true);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->mode = new LineMode( Line::CompositionLine);
}

void UML_KEditor::onChangeNameClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(true);
	}
	Scene::SceneGetInstance()->changeItemName();
}


void UML_KEditor::onGroupItemClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGroup->setChecked(true);
		ui.actionUnGroup->setChecked(false);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->groupItem();
}

void UML_KEditor::onUnGroupItemClicked(){

	if(Scene::SceneGetInstance()->mode){
	
		ui.actionUseCase->setChecked(false);
		ui.actionClass->setChecked(false);
		ui.actionChoose->setChecked(false);
		ui.actionAssociation->setChecked(false);
		ui.actionGeneration->setChecked(false);
		ui.actionComposition->setChecked(false);
		ui.actionGroup->setChecked(false);
		ui.actionUnGroup->setChecked(true);
		ui.actionText->setCheckable(false);
	}
	Scene::SceneGetInstance()->unGroupItem();
}


