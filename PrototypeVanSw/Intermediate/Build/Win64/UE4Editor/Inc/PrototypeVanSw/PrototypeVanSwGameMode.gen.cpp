// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "PrototypeVanSw/PrototypeVanSwGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePrototypeVanSwGameMode() {}
// Cross Module References
	PROTOTYPEVANSW_API UClass* Z_Construct_UClass_APrototypeVanSwGameMode_NoRegister();
	PROTOTYPEVANSW_API UClass* Z_Construct_UClass_APrototypeVanSwGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_PrototypeVanSw();
// End Cross Module References
	void APrototypeVanSwGameMode::StaticRegisterNativesAPrototypeVanSwGameMode()
	{
	}
	UClass* Z_Construct_UClass_APrototypeVanSwGameMode_NoRegister()
	{
		return APrototypeVanSwGameMode::StaticClass();
	}
	struct Z_Construct_UClass_APrototypeVanSwGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APrototypeVanSwGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_PrototypeVanSw,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APrototypeVanSwGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "PrototypeVanSwGameMode.h" },
		{ "ModuleRelativePath", "PrototypeVanSwGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APrototypeVanSwGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APrototypeVanSwGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APrototypeVanSwGameMode_Statics::ClassParams = {
		&APrototypeVanSwGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_APrototypeVanSwGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APrototypeVanSwGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APrototypeVanSwGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APrototypeVanSwGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APrototypeVanSwGameMode, 339148940);
	template<> PROTOTYPEVANSW_API UClass* StaticClass<APrototypeVanSwGameMode>()
	{
		return APrototypeVanSwGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APrototypeVanSwGameMode(Z_Construct_UClass_APrototypeVanSwGameMode, &APrototypeVanSwGameMode::StaticClass, TEXT("/Script/PrototypeVanSw"), TEXT("APrototypeVanSwGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APrototypeVanSwGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
