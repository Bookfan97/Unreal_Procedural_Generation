﻿#pragma once

struct FCornerCoordinates
{
	int32 upperLeftX;
	int32 upperLeftY;
	int32 bottomRightX;
	int32 bottomRightY;
};

class FloorNode
{
public:
	FloorNode();
	FloorNode(const FCornerCoordinates& Coordinates);
	~FloorNode();

FORCEINLINE FCornerCoordinates GetCornerCoordinates() const {return CornerCoordinates;}
	FORCEINLINE void SetCornerCoordinates(FCornerCoordinates Coordinates) {CornerCoordinates = Coordinates;}
private:
	FCornerCoordinates CornerCoordinates;
};

