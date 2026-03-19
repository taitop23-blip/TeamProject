// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemWidget.generated.h"


class UCanvasPanel;
class USizeBox;
class UBorder;
class UImage;
class AIntentorySystemCppCharacter;
UCLASS()
class INTENTORYSYSTEMCPP_API UItemWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UCanvasPanel* Canvas;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	USizeBox* BackgroundSizeBox;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UBorder* BackgroundBorder;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "UI")
	UImage* ItemImage;

	AIntentorySystemCppCharacter* CharacterReference;

	FVector2D Size;

	virtual void NativeConstruct() override;

	void Refresh(AActor* ItemToAdd);

};
