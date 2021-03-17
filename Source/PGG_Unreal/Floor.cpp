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
		float percentChanceOfSplit = (float) floorLength/ (float) floorGridSizeX;
		float chance = FMath::FRandRange(0.1f, 1.f);
		if (chance > percentChanceOfSplit)
		{
			return false;
		}
		if (floorLength >= 2 * roomMinY)
		{
			return true;
		}
	}
	else if (Orientation == ESplitOrientation::ESO_Vertical)
	{
		int32 floorWidth = CornerCoordinates.bottomRightX - CornerCoordinates.upperLeftX;
		float percentChanceOfSplit = floorWidth/floorGridSizeY;
		float chance = FMath::FRandRange(0.1f, 1.f);
		if (chance > percentChanceOfSplit)
		{
			return false;
		}
		if (floorWidth >=  2*roomMinX)
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
			TSharedPtr<FloorNode> B(new FloorNode());
			TSharedPtr<FloorNode> C(new FloorNode());

			SplitHorizontal(InNode, B, C);
			return true;
		}
		else if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Vertical))
		{
			TSharedPtr<FloorNode> B(new FloorNode());
			TSharedPtr<FloorNode> C(new FloorNode());

			SplitVertical(InNode, B, C);
			return true;
		}
	}
	else if(HorizontalOrVertical == 1)
	{
		if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Vertical))
		{
			TSharedPtr<FloorNode> B(new FloorNode());
			TSharedPtr<FloorNode> C(new FloorNode());

			SplitVertical(InNode, B, C);
			return true;
		}
		else if (ShouldSplitNode(InNode, ESplitOrientation::ESO_Horizontal))
		{
			TSharedPtr<FloorNode> B(new FloorNode());
			TSharedPtr<FloorNode> C(new FloorNode());

			SplitHorizontal(InNode, B, C);
			return true;
		}
	}
	return false;
}

void Floor::SplitHorizontal(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC)
{
	int32 splitPointY = FMath::RandRange(InA->GetCornerCoordinates().upperLeftY + roomMinY, InA->GetCornerCoordinates().bottomRightY - roomMinY);
	FCornerCoordinates cornerCoordinatesB;
	cornerCoordinatesB.upperLeftX = InA->GetCornerCoordinates().upperLeftX;
	cornerCoordinatesB.upperLeftY = InA->GetCornerCoordinates().upperLeftY;
	cornerCoordinatesB.bottomRightX = InA->GetCornerCoordinates().bottomRightX;
	cornerCoordinatesB.bottomRightY = splitPointY;

	InB->SetCornerCoordinates(cornerCoordinatesB);
	PartionedFloor.Push(InB);
	
	FCornerCoordinates cornerCoordinatesC;
	cornerCoordinatesC.upperLeftX = InA->GetCornerCoordinates().upperLeftX;
	cornerCoordinatesC.upperLeftY = splitPointY;
	cornerCoordinatesC.bottomRightY = InA->GetCornerCoordinates().bottomRightY;
	cornerCoordinatesC.bottomRightX = InA->GetCornerCoordinates().bottomRightX;

	InC->SetCornerCoordinates(cornerCoordinatesC);
	PartionedFloor.Push(InC);
}

void Floor::SplitVertical(TSharedPtr<FloorNode> InA, TSharedPtr<FloorNode> InB, TSharedPtr<FloorNode> InC)
{
	int32 splitPointX = FMath::RandRange(InA->GetCornerCoordinates().upperLeftX + roomMinX, InA->GetCornerCoordinates().bottomRightX - roomMinX);
	FCornerCoordinates cornerCoordinatesB;
	cornerCoordinatesB.upperLeftX = InA->GetCornerCoordinates().upperLeftX;
	cornerCoordinatesB.upperLeftY = InA->GetCornerCoordinates().upperLeftY;
	cornerCoordinatesB.bottomRightX = splitPointX;
	cornerCoordinatesB.bottomRightY = InA->GetCornerCoordinates().bottomRightY;

	InB->SetCornerCoordinates(cornerCoordinatesB);
	PartionedFloor.Push(InB);

	FCornerCoordinates cornerCoordinatesC;
	cornerCoordinatesC.upperLeftX = splitPointX;
	cornerCoordinatesC.upperLeftY = InA->GetCornerCoordinates().upperLeftY;
	cornerCoordinatesC.bottomRightY = InA->GetCornerCoordinates().bottomRightY;
	cornerCoordinatesC.bottomRightX = InA->GetCornerCoordinates().bottomRightX;

	InC->SetCornerCoordinates(cornerCoordinatesC);
	PartionedFloor.Push(InC);
}

Floor::~Floor()
{
}
