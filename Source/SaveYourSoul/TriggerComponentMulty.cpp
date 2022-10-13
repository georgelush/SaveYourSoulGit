// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponentMulty.h"

UTriggerComponentMulty::UTriggerComponentMulty()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponentMulty::BeginPlay()
{
	Super::BeginPlay();

    OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponentMulty::OnOverlapBegin);
    OnComponentEndOverlap.AddDynamic(this, &UTriggerComponentMulty::OnOverlapEnd);
    Counter = 0;
}

void UTriggerComponentMulty::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UTriggerComponentMulty::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}

void UTriggerComponentMulty::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

    if (Mover == nullptr)
    {
        return;
    }
    UE_LOG(LogTemp, Display, TEXT("Being overlap %s"), *OtherActor->GetName());
    
    bool HasAcceptableTag = OtherActor->ActorHasTag(AcceptableActorTag);
    if (HasAcceptableTag)
    {
         UPrimitiveComponent* Component = Cast<UPrimitiveComponent>(OtherActor->GetRootComponent());
        if (Component != nullptr)
        {
            Component->SetSimulatePhysics(false);
        }
        Counter = Counter + 1;
        UE_LOG(LogTemp, Display, TEXT("Counter is: %d"), Counter);
        OtherActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
        Mover->SetRotationMove(true); 
        UE_LOG(LogTemp, Display, TEXT("Mover is set"));
    }
    else
    {
        Mover->SetShouldMove(false);
        Mover->SetRotationMove(false);
    }
}

void UTriggerComponentMulty::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    bool HasAcceptableTag = OtherActor->ActorHasTag(AcceptableActorTag);
    if (HasAcceptableTag)
    {
        
    }
    
    UE_LOG(LogTemp, Display, TEXT("overlapEND"));
}