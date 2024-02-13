// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile_dm.generated.h"

UCLASS()
class ONLINE_RPG_API AProjectile_dm : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile_dm();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

protected:
    virtual void Destroyed() override;

    UFUNCTION(Category = "Projectile")
    void OnProjectileImpact(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
    // �ݸ��� �׽�Ʈ�� ���Ǵ� ���Ǿ� ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class USphereComponent* SphereComponent;

    // ������Ʈ�� ���־� ǥ���� �����ϴ� ����ƽ �޽�
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* StaticMesh;

    // �߻�ü �������� ó���ϴ� �����Ʈ ������Ʈ
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UProjectileMovementComponent* ProjectileMovementComponent;

    // �߻�ü�� �ٸ� ������Ʈ�� ������ ��ġ�� ������ �� ���Ǵ� ��ƼŬ
    UPROPERTY(EditAnywhere, Category = "Effects")
    class UParticleSystem* ExplosionEffect;

    //�� �߻�ü�� ���� ����� Ÿ�԰� �����
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
    TSubclassOf<class UDamageType> DamageType;

    //�� �߻�ü�� ���ϴ� �����
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Damage")
    float Damage;

};
