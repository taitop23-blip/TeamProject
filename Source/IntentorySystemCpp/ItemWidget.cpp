// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemWidget.h"
#include "IntentorySystemCppCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "ItemBase.h"
#include "Components/Image.h"
#include "InventoryComponent.h"
#include "Components/SizeBox.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void UItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	CharacterReference = Cast<AIntentorySystemCppCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (CharacterReference) {
		Refresh(CharacterReference->ItemToAdd);
	}
}

void UItemWidget::Refresh(AActor* ItemToAdd)
{
	AItemBase* Item = Cast<AItemBase>(ItemToAdd);

	if (Item) {

		ItemImage->SetBrushFromMaterial(Item->GetIcon());

		Size = FVector2D(Item->GetDimensions().X * CharacterReference->InventoryComponent->TileSize, Item->GetDimensions().Y * CharacterReference->InventoryComponent->TileSize);

		BackgroundSizeBox->SetWidthOverride(Size.X);
		BackgroundSizeBox->SetHeightOverride(Size.Y);

		UCanvasPanelSlot* ImageAsCanvasSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(ItemImage);

		ImageAsCanvasSlot->SetSize(Size);
	}

}
