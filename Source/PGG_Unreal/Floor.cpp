#include "Floor.h"

#include "FloorNode.h"

Floor::Floor()
{
	floorGridSizeX = 5;
	floorGridSizeY = 5;
	roomMinX = 1;
	roomMinY = 1;
}

void Floor::Partition()
{
	FCornerCoordinates CornerCoordinatesA = {0,0,floorGridSizeX, floorGridSizeY};
	FloorNodes.Push(TSharedPtr<FloorNode>(new FloorNode(CornerCoordinatesA)));
	while (FloorNodes.Num() > 0)
	{
		TSharedPtr<FloorNode> A = FloorNodes.Pop();
		UE_LOG(LogTemp, Warning, TEXT("FLOOR NODE OFF STACK"));
	}
}

int32 Floor::RandomBinaryValue()
{
	return 3;
}

bool Floor::ShouldSplitNode(TSharedPtr<FloorNode> InNode, ESplitOrientation Orientation)
{
	return false;
}

bool Floor::SplitAttempt(TSharedPtr<FloorNode> InNode)
{
	return false;
}

void Floor::SplitHorizontal(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC)
{
}

void Floor::SplitVertical(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC)
{
}

Floor::~Floor()
{
}
