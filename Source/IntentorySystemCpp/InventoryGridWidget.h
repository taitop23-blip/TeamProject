// Fill out your copyright notice in the Description page of Project Settings.

// InventoryGridWidget.h

#pragma once

// Imported
#include "Blueprint/UserWidget.h"
#include "Components/Border.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "InventoryDataStructs.h"

// Engine
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryGridWidget.generated.h"

class UCanvasPanel;
class UBorder;
class AIntentorySystemCppCharacter;
class UInventoryComponent;

UCLASS()
class INTENTORYSYSTEMCPP_API UInventoryGridWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UBorder* GridBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* GridCanvasPanel;

	AIntentorySystemCppCharacter* CharacterReference;

	UInventoryComponent* InventoryComponent;

	UPanelSlot* PanelSolt;


	int32 Columns;
	int32 Rows;
	float TileSize;

	FLines* LineStructData;

	TArray<float> StartX;
	TArray<float> StartY;
	TArray<float> EndX;
	TArray<float> EndY;
	

	// Functions

	virtual void NativeConstruct() override;
	void CreateLineSegments();

	virtual int32 NativePaint(const FPaintArgs& Args, 
		const FGeometry& AllottedGeometry, 
		const FSlateRect& MyCullingRect, 
		FSlateWindowElementList& OutDrawElements, 
		int32 LayerId, 
		const FWidgetStyle& InWidgetStyle, 
		bool bParentEnabled) const override;

public:

	void Refresh();
};
