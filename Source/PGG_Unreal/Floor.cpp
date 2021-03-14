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
		bool bNodeWasSplit = SplitAttempt(A);
		if (bNodeWasSplit)
		{
			PartionedFloor.Push(A);
		}
	}
}

int32 Floor::RandomBinaryValue()
{
	return FMath::RandRange(0,1);
}

bool Floor::ShouldSplitNode(TSharedPtr<FloorNode> InNode, ESplitOrientation Orientation)
{
	FCornerCoordinates CornerCoordinates = InNode->GetCornerCoordinates();
	if (Orientation == ESplitOrientation::ESO_Horizontal)
	{
		int32 floorLength = CornerCoordinates.bottomRightY - CornerCoordinates.upperLeftY;
		if (floorLength > roomMinY)
		{
			return true;
		}
	}
	else if (Orientation == ESplitOrientation::ESO_Vertical)
	{
		int32 floorWidth = CornerCoordinates.bottomRightX - CornerCoordinates.upperLeftX;
		if (floorWidth > roomMinX)
		{
			return true;
		}
	}
	return false;
}

bool Floor::SplitAttempt(TSharedPtr<FloorNode> InNode)
{
	int32 HorizontalOrVertical = RandomBinaryValue();
	if (HorizontalOrVertical == 0)
	{
		if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Horizontal))
		{
			
		}
		else if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Vertical))
		{
			
		}
	}
	else
	{
		if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Vertical))
		{
			
		}
		else if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Horizontal))
		{
			
		}
	}
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
