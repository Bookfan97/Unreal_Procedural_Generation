#include "FloorNode.h"

FloorNode::FloorNode()
{
 UE_LOG(LogTemp, Warning, TEXT("FLOOR NODE CREATED"));
}

FloorNode::FloorNode(const FCornerCoordinates& Coordinates)
{
 CornerCoordinates.upperLeftX = Coordinates.upperLeftX;
 CornerCoordinates.upperLeftY = Coordinates.upperLeftY;
 CornerCoordinates.bottomRightX = Coordinates.bottomRightX;
 CornerCoordinates.bottomRightY = Coordinates.bottomRightY;
}

 FloorNode::~FloorNode()
{
 UE_LOG(LogTemp, Warning, TEXT("FLOOR NODE DESTROYED"));
}