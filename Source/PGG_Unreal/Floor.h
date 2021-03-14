#pragma once

enum class ESplitOrientation
{
	ESO_Horizontal,
	ESO_Vertical
};

class FloorNode;
class Floor
{
public:
	Floor();
	void Partition();
	int32 RandomBinaryValue();
	bool ShouldSplitNode(TSharedPtr<FloorNode> InNode, ESplitOrientation Orientation);
	bool SplitAttempt(TSharedPtr<FloorNode> InNode);
	void SplitHorizontal(TSharedPtr<FloorNode> InA,TSharedPtr<FloorNode> InB,TSharedPtr<FloorNode> InC);
	void SplitVertical(TSharedPtr<FloorNode> InA,TSharedPtr<FloorNode> InB,TSharedPtr<FloorNode> InC);
	~Floor();

	FORCEINLINE TArray<TSharedPtr<FloorNode>> GetPartitionedFloor() const {return PartionedFloor;}
private:

	TArray<TSharedPtr<FloorNode>> FloorNodes;
	TArray<TSharedPtr<FloorNode>> PartionedFloor;
	
	int32 floorGridSizeX;
	int32 floorGridSizeY;
	int32 roomMinX;
	int32 roomMinY;
};
