#include "Floor.h"

Floor::Floor()
{
	
}

void Floor::Partition()
{
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
