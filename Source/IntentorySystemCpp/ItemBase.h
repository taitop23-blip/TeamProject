// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UMaterialInstance;
UCLASS()
class INTENTORYSYSTEMCPP_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AItemBase();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	USphereComponent* Sphere;

	FIntPoint GetDimensions() const;

	UMaterialInstance* GetIcon();


protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Item Info | Dimensions")
	FIntPoint Dimensions;

	UPROPERTY(EditAnywhere, Category = "Item Info | Icon")
	UMaterialInstance* Icon;


};
