#include "ContentsHelper.h"

UContentsHelper::UContentsHelper() 
{
}

UContentsHelper::~UContentsHelper() 
{
}

FVector UContentsHelper::GetMousePos()
{
	return GEngine->MainWindow.GetMousePosition();
}