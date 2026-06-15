// Copyright Jakub Kaczor

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PawnExtensionsComponentBase.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WARRIORRPG_API UPawnExtensionsComponentBase : public UActorComponent
{
	GENERATED_BODY()

protected:
	template<class T>
	T* GetOwningPawn() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, APawn>::Value, "'T' template parameter get GetPawn must be derived from APawn");
		return CastChecked<T>(GetOwner());
	}
		
	APawn* GetOwningPawn() const
	{
		return GetOwningPawn<APawn>();
	}
	
	template<class T>
	T* GetOwningController() const
	{
		static_assert(TPointerIsConvertibleFromTo<T, AController>::Value, "'T' template parameter get GetController must be derived from AController");
		return GetOwningPawn<APawn>()->GetController<T>();
	}
	
};
