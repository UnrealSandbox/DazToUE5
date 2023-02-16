#include "DazToUnrealMLDeformer.h"
#include "DazToUnrealSettings.h"

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 0
#include "AssetRegistry/AssetRegistryModule.h"
#include "AbcImportSettings.h"
#include "AutomatedAssetImportData.h"
#include "AlembicImportFactory.h"
#include "MLDeformerAsset.h"
#include "MLDeformerModel.h"
#endif
#include "AssetToolsModule.h"
#include "Dom/JsonObject.h"

DEFINE_LOG_CATEGORY(LogDazToUnrealMLDeformer);

void FDazToUnrealMLDeformer::ImportMLDeformerAssets(FDazToUnrealMLDeformerParams& DazToUnrealMLDeformerParams)
{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 0
	UDazToUnrealSettings* CachedSettings = GetMutableDefault<UDazToUnrealSettings>();

	FString AlembicFilePath = DazToUnrealMLDeformerParams.JsonImportData->GetStringField(TEXT("AlembicFile"));

	TObjectPtr<UAbcImportSettings> AlembicImportSettings = UAbcImportSettings::Get();
	AlembicImportSettings->ImportType = EAlembicImportType::GeometryCache;
	AlembicImportSettings->GeometryCacheSettings.bFlattenTracks = false;
	AlembicImportSettings->GeometryCacheSettings.bStoreImportedVertexNumbers = true;
	AlembicImportSettings->GeometryCacheSettings.CompressedPositionPrecision = 0.001f;

	UAlembicImportFactory* AlembicFactory = NewObject<UAlembicImportFactory>(UAlembicImportFactory::StaticClass());
	AlembicFactory->AddToRoot();

	TArray<FString> FileNames;
	FileNames.Add(AlembicFilePath);

	UAutomatedAssetImportData* ImportData = NewObject<UAutomatedAssetImportData>(UAutomatedAssetImportData::StaticClass());
	ImportData->FactoryName = TEXT("AlembicFactory");
	ImportData->Factory = AlembicFactory;
	ImportData->Filenames = FileNames;
	ImportData->bReplaceExisting = true;
	ImportData->DestinationPath = CachedSettings->DeformerImportDirectory.Path;

	TArray<UObject*> ImportedAssets;
	FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
	ImportedAssets = AssetToolsModule.Get().ImportAssetsAutomated(ImportData);
	AlembicFactory->RemoveFromRoot();

	DazToUnrealMLDeformerParams.AssetName = TEXT("MLD_") + FPaths::GetBaseFilename(AlembicFilePath);
	CreateMLDeformer(DazToUnrealMLDeformerParams);

#endif
}

void FDazToUnrealMLDeformer::CreateMLDeformer(FDazToUnrealMLDeformerParams& DazToUnrealMLDeformerParams)
{
#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION > 0
	const UDazToUnrealSettings* CachedSettings = GetDefault<UDazToUnrealSettings>();

	// Get the AssetTools for finding factories
	static const FName NAME_AssetTools = "AssetTools";
	const IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>(NAME_AssetTools).Get();

	// Find the factory that supports UMLDeformerAsset.  It's private so it can't be access directly.
	TArray<UFactory*> Factories = AssetTools.GetNewAssetFactories();
	UFactory* Factory = nullptr;
	for (UFactory* CheckFactory : Factories)
	{
		if (CheckFactory->SupportedClass == UMLDeformerAsset::StaticClass())
		{
			Factory = CheckFactory;
		}
	}
	if (!Factory) return;

	// Create a new item in the Content Browser using the factory
	const FString PackageName = CachedSettings->DeformerImportDirectory.Path / DazToUnrealMLDeformerParams.AssetName;
	UPackage* AssetPackage = CreatePackage(*PackageName);
	EObjectFlags Flags = RF_Public | RF_Standalone;

	UObject* CreatedAsset = Factory->FactoryCreateNew(UMLDeformerAsset::StaticClass(), AssetPackage, FName(*DazToUnrealMLDeformerParams.AssetName), Flags, NULL, GWarn);

	if (CreatedAsset)
	{
		FAssetRegistryModule::AssetCreated(CreatedAsset);
		AssetPackage->MarkPackageDirty();
	}

	// Set data after creation
	if (UMLDeformerAsset* Deformer = Cast<UMLDeformerAsset>(CreatedAsset))
	{
		//FTransform Transform(FRotator(), FVector(0.0f, 0.0f, 1.1f), FVector(-1.0f, 0.0f, 0.0f));
		//Deformer->GetModel()->SetAlignmentTransform(Transform);
		//Deformer->GetModel()-> = DazToUnrealMLDeformerParams.AnimationAsset;
		DazToUnrealMLDeformerParams.OutAsset = Deformer;
	}
#endif
}