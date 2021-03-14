#include "FloorNode.h"

int32 FloorNode::FloorNodeCount = 0;

FloorNode::FloorNode()
{
 UE_LOG(LogTemp, Warning, TEXT("FLOOR NODE CREATED"));
 FloorNodeCount++;
}

FloorNode::FloorNode(const FCornerCoordinates& Coordinates)
{
 CornerCoordinates.upperLeftX = Coordinates.upperLeftX;
 CornerCoordinates.upperLeftY = Coordinates.upperLeftY;
 CornerCoordinates.bottomRightX = Coordinates.bottomRightX;
 CornerCoordinates.bottomRightY = Coordinates.bottomRightY;
 FloorNodeCount++;
}

 FloorNode::~FloorNode()
{
 UE_LOG(LogTemp, Warning, TEXT("FLOOR NODE DESTROYED"));
 FloorNodeCount--;
}