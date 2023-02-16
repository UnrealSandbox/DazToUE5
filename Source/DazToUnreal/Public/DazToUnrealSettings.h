#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Engine/EngineTypes.h"
#include "UObject/SoftObjectPath.h"
#include "DazToUnrealMaterialPack.h"
#include "DazToUnrealSettings.generated.h"

/**
* Settings for the DazToUnreal Plugin.
*/
UCLASS(config = Game, defaultconfig)
class DAZTOUNREAL_API UDazToUnrealSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UDazToUnrealSettings(const FObjectInitializer& ObjectInitializer)
	{
		Port = 32345;
		ImportDirectory.Path = TEXT("/Game/DazToUnreal");
		AnimationImportDirectory.Path = TEXT("/Game/DazToUnreal/Animation");
		DeformerImportDirectory.Path = TEXT("/Game/DazToUnreal/MLDeformer");
		PoseImportDirectory.Path = TEXT("/Game/DazToUnreal/Pose");
		ShowFBXImportDialog = false;
		FrameZeroIsReferencePose = false;
		FixBoneRotationsOnImport = true;
		ZeroRootRotationOnImport = true;
		CombineIdenticalMaterials = true;
		UpdatedFbxAsAscii = false;

		Genesis1Skeleton = FSoftObjectPath(TEXT("/DazToUnreal/Genesis1BaseSkeleton.Genesis1BaseSkeleton"));
		Genesis3Skeleton = FSoftObjectPath(TEXT("/DazToUnreal/Genesis3BaseSkeleton.Genesis3BaseSkeleton"));
		Genesis8Skeleton = FSoftObjectPath(TEXT("/DazToUnreal/Genesis8BaseSkeleton.Genesis8BaseSkeleton"));
		OtherSkeletons.Add(TEXT("Genesis8_1Male"), FSoftObjectPath(TEXT("/DazToUnreal/Genesis8BaseSkeleton.Genesis8BaseSkeleton")));
		OtherSkeletons.Add(TEXT("Genesis8_1Female"), FSoftObjectPath(TEXT("/DazToUnreal/Genesis8BaseSkeleton.Genesis8BaseSkeleton")));

		SkeletonPostProcessAnimation.Add(FSoftObjectPath(TEXT("/DazToUnreal/Genesis3BaseSkeleton.Genesis3BaseSkeleton")), FSoftClassPath(TEXT("/DazToUnreal/Genesis3JCMPostProcess.Genesis3JCMPostProcess_C")));
		SkeletonPostProcessAnimation.Add(FSoftObjectPath(TEXT("/DazToUnreal/Genesis8BaseSkeleton.Genesis8BaseSkeleton")), FSoftClassPath(TEXT("/DazToUnreal/Genesis8JCMPostProcess.Genesis8JCMPostProcess_C")));

		AddIKBones = true;

		/*BaseShaderMaterials.Add(TEXT("Daz Studio Default"), FSoftObjectPath(TEXT("/DazToUnreal/DSDBaseMaterial.DSDBaseMaterial")));
		BaseShaderMaterials.Add(TEXT("omUberSurface"), FSoftObjectPath(TEXT("/DazToUnreal/omUberBaseMaterial.omUberBaseMaterial")));
		BaseShaderMaterials.Add(TEXT("AoA_Subsurface"), FSoftObjectPath(TEXT("/DazToUnreal/AoASubsurfaceBaseMaterial.AoASubsurfaceBaseMaterial")));
		BaseShaderMaterials.Add(TEXT("Iray Uber"), FSoftObjectPath(TEXT("/DazToUnreal/IrayUberBaseMaterial.IrayUberBaseMaterial")));
		BaseShaderMaterials.Add(TEXT("PBRSkin"), FSoftObjectPath(TEXT("/DazToUnreal/BasePBRSkinMaterial.BasePBRSkinMaterial")));

		SkinShaderMaterials.Add(TEXT("Daz Studio Default"), FSoftObjectPath(TEXT("/DazToUnreal/DSDBaseMaterial.DSDBaseMaterial")));
		SkinShaderMaterials.Add(TEXT("omUberSurface"), FSoftObjectPath(TEXT("/DazToUnreal/omUberSkinMaterial.omUberSkinMaterial")));
		SkinShaderMaterials.Add(TEXT("AoA_Subsurface"), FSoftObjectPath(TEXT("/DazToUnreal/AoASubsurfaceSkinMaterial.AoASubsurfaceSkinMaterial")));
		SkinShaderMaterials.Add(TEXT("Iray Uber"), FSoftObjectPath(TEXT("/DazToUnreal/IrayUberSkinMaterial.IrayUberSkinMaterial")));
		SkinShaderMaterials.Add(TEXT("PBRSkin"), FSoftObjectPath(TEXT("/DazToUnreal/BasePBRSkinMaterial.BasePBRSkinMaterial")));

		BaseMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseMaterial.BaseMaterial"));
		BaseAlphaMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		BaseMaskedMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseMaskedMaterial.BaseMaskedMaterial"));
		BaseSkinMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseSSSSkinMaterial.BaseSSSSkinMaterial"));
		BaseHairMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseHairMaterial.BaseHairMaterial"));
		BaseScalpMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseScalpMaterial.BaseScalpMaterial"));
		BaseEyeMoistureMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		BaseCorneaMaterial = FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		NoDrawMaterial = FSoftObjectPath(TEXT("/DazToUnreal/NoDrawMaterial.NoDrawMaterial"));*/

		UseOriginalMaterialName = false;
		UseInternalMorphName = false;

		ArmsSubSurfaceOpacityGenesis1Texture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		FaceSubSurfaceOpacityGenesis1Texture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		LegsSubSurfaceOpacityGenesis1Texture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		TorsoSubSurfaceOpacityGenesis1Texture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));

		ArmsSubSurfaceOpacityGenesis3MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		FaceSubSurfaceOpacityGenesis3MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		LegsSubSurfaceOpacityGenesis3MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		TorsoSubSurfaceOpacityGenesis3MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));

		ArmsSubSurfaceOpacityGenesis3FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		FaceSubSurfaceOpacityGenesis3FemaleTexture = FSoftObjectPath(TEXT("/DazToUnreal/SSSTextures/Genesis3Female/FaceSSSTransparency.FaceSSSTransparency"));
		LegsSubSurfaceOpacityGenesis3FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		TorsoSubSurfaceOpacityGenesis3FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));

		ArmsSubSurfaceOpacityGenesis8MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		FaceSubSurfaceOpacityGenesis8MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		LegsSubSurfaceOpacityGenesis8MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		TorsoSubSurfaceOpacityGenesis8MaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));

		ArmsSubSurfaceOpacityGenesis8FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		FaceSubSurfaceOpacityGenesis8FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		LegsSubSurfaceOpacityGenesis8FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));
		TorsoSubSurfaceOpacityGenesis8FemaleTexture = FSoftObjectPath(TEXT("/Engine/EngineResources/WhiteSquareTexture.WhiteSquareTexture"));

		MaterialPropertyMapping.Add(TEXT("Specular Color"), TEXT("Glossy Specular"));
		MaterialPropertyMapping.Add(TEXT("Specular Strength"), TEXT("Glossy Layered Weight"));
		MaterialPropertyMapping.Add(TEXT("Specular Strength Texture"), TEXT("Glossy Layered Weight Texture"));
		MaterialPropertyMapping.Add(TEXT("Specular Strength Texture Active"), TEXT("Glossy Layered Weight Texture Active"));

		DefaultSkinDiffuseSubsurfaceColorWeight = 0.5f;
		DefaultEyeMoistureOpacity = 0.01f;
	}

	virtual FName GetCategoryName() const { return FName(TEXT("Plugins")); }

	/** The port that DazToUnreal will communicate on */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (ConfigRestartRequired = true))
		int32 Port;

	/** Directory characters and props will be imported to */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (RelativeToGameContentDir, LongPackageName))
		FDirectoryPath ImportDirectory;

	/** Directory animations will be imported to */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (RelativeToGameContentDir, LongPackageName))
		FDirectoryPath AnimationImportDirectory;

	/** Directory animations will be imported to */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (RelativeToGameContentDir, LongPackageName))
		FDirectoryPath DeformerImportDirectory;

	/** Directory PoseAssets will be imported to */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (RelativeToGameContentDir, LongPackageName))
		FDirectoryPath PoseImportDirectory;

	/** Show the FBX Import dialog when importing the udpated FBX file */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings, meta = (RelativeToGameContentDir, LongPackageName))
		bool ShowFBXImportDialog;

	/** Set the default pose for the character to match frame 0 */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings)
		bool FrameZeroIsReferencePose;

	/** Updates the bones to use a locale rotation.  This currently breaks animations coming from Daz Studio. */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings)
		bool FixBoneRotationsOnImport;

	/** Updates the bones to use a locale rotation.  This currently breaks animations coming from Daz Studio. */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings)
		bool ZeroRootRotationOnImport;

	/** Combines identical materials on import. Also combines the geometry sections. */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings)
		bool CombineIdenticalMaterials;

	/** If true write the Updated (intermediate) FBX file as Ascii */
	UPROPERTY(config, EditAnywhere, Category = PluginSettings)
		bool UpdatedFbxAsAscii;

	/** Skeleton to use for Genesis 1 characters */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings, meta = (AllowedClasses = "Skeleton"))
		FSoftObjectPath Genesis1Skeleton;

	/** Skeleton to use for Genesis 3 characters */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings, meta = (AllowedClasses = "Skeleton"))
		FSoftObjectPath Genesis3Skeleton;

	/** Skeleton to use for Genesis 8 characters */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings, meta = (AllowedClasses = "Skeleton"))
		FSoftObjectPath Genesis8Skeleton;

	/** Used to save the skeleton to use for other character types */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings)
		TMap<FString, FSoftObjectPath> OtherSkeletons;

	/** A mapping of default post process animations for different skeletons */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings)
		TMap<FSoftObjectPath, FSoftClassPath> SkeletonPostProcessAnimation;

	/** Add ik bones to the skeleton */
	UPROPERTY(config, EditAnywhere, Category = SkeletonSettings)
		bool AddIKBones;

	/** Material Packs to use.  Order matters, first matching material will be used.*/
	UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "DazToUnrealMaterialPack"))
		TArray<FSoftObjectPath> MaterialPacks;

	///** Used to set the default Material to use for a shader type from Daz Studio */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings)
	//	TMap<FString, FSoftObjectPath> SkinShaderMaterials;

	///** Override for the base that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseMaterial;

	///** Override for the base with alpha that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseAlphaMaterial;

	///** Override for the base with mask that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseMaskedMaterial;

	///** Override for the base skin material that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseSkinMaterial;

	///** Override for the base hair material that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseHairMaterial;

	///** Override for the base scalp material that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseScalpMaterial;

	///** Override for the base eye moisture material that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseEyeMoistureMaterial;

	///** Override for the base cornea material that material instances will be derived from */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath BaseCorneaMaterial;

	///** Override for the material to use for surfaces that shouldn't be drawn */
	//UPROPERTY(config, EditAnywhere, Category = MaterialSettings, meta = (AllowedClasses = "Material"))
	//	FSoftObjectPath NoDrawMaterial;

	/** Used to change the name of material parameters at import time */
	UPROPERTY(config, EditAnywhere, Category = MaterialSettings)
		TMap<FString, FString> MaterialPropertyMapping;

	/** Default Diffuse Subsurface Color Weight to use for Skin Materials */
	UPROPERTY(config, EditAnywhere, Category = MaterialSettings)
		float DefaultSkinDiffuseSubsurfaceColorWeight;

	/** Default Opacity to use for EyeMoisture, Tears, etc */
	UPROPERTY(config, EditAnywhere, Category = MaterialSettings)
		float DefaultEyeMoistureOpacity;

	/** Use Original Name of Material */
	UPROPERTY(config, EditAnywhere, Category = MaterialSettings)
		bool UseOriginalMaterialName;

	/** Use the internal name rather than the display name when transfering morphs */
	UPROPERTY(config, EditAnywhere, Category = MorphSettings)
		bool UseInternalMorphName;

	/** Override for the sub surface scatter opacity texture for the arms and fingernails for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath ArmsSubSurfaceOpacityGenesis1Texture;

	/** Override for the sub surface scatter opacity texture for the face, ears, and lips for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath FaceSubSurfaceOpacityGenesis1Texture;

	/** Override for the sub surface scatter opacity texture for the legs and toenails for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath LegsSubSurfaceOpacityGenesis1Texture;

	/** Override for the sub surface scatter opacity texture for the torso for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath TorsoSubSurfaceOpacityGenesis1Texture;

	/** Override for the sub surface scatter opacity texture for the arms and fingernails for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath ArmsSubSurfaceOpacityGenesis3MaleTexture;

	/** Override for the sub surface scatter opacity texture for the face, ears, and lips for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath FaceSubSurfaceOpacityGenesis3MaleTexture;

	/** Override for the sub surface scatter opacity texture for the legs and toenails for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath LegsSubSurfaceOpacityGenesis3MaleTexture;

	/** Override for the sub surface scatter opacity texture for the torso for Genesis 3 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath TorsoSubSurfaceOpacityGenesis3MaleTexture;

	/** Override for the sub surface scatter opacity texture for the arms and fingernails for Genesis 3 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath ArmsSubSurfaceOpacityGenesis3FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the face, ears, and lips for Genesis 3 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath FaceSubSurfaceOpacityGenesis3FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the legs and toenails for Genesis 3 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath LegsSubSurfaceOpacityGenesis3FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the torso for Genesis 3 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis3Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath TorsoSubSurfaceOpacityGenesis3FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the arms and fingernails for Genesis 8 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath ArmsSubSurfaceOpacityGenesis8MaleTexture;

	/** Override for the sub surface scatter opacity texture for the face, ears, and lips for Genesis 8 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath FaceSubSurfaceOpacityGenesis8MaleTexture;

	/** Override for the sub surface scatter opacity texture for the legs and toenails for Genesis 8 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath LegsSubSurfaceOpacityGenesis8MaleTexture;

	/** Override for the sub surface scatter opacity texture for the torso for Genesis 8 Male  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Male, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath TorsoSubSurfaceOpacityGenesis8MaleTexture;

	/** Override for the sub surface scatter opacity texture for the arms and fingernails for Genesis 8 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath ArmsSubSurfaceOpacityGenesis8FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the face, ears, and lips for Genesis 8 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath FaceSubSurfaceOpacityGenesis8FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the legs and toenails for Genesis 8 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath LegsSubSurfaceOpacityGenesis8FemaleTexture;

	/** Override for the sub surface scatter opacity texture for the torso for Genesis 8 Female  */
	UPROPERTY(config, EditAnywhere, Category = SubSurfaceScatterGenesis8Female, meta = (AllowedClasses = "Texture"))
		FSoftObjectPath TorsoSubSurfaceOpacityGenesis8FemaleTexture;


	FSoftObjectPath FindMaterial(FString ShaderName, EDazMaterialType MaterialType) const
	{
		for (FSoftObjectPath MaterialPackPath : MaterialPacks)
		{
			if (UDazToUnrealMaterialPack* MaterialPack = Cast<UDazToUnrealMaterialPack>(MaterialPackPath.TryLoad()))
			{
				FSoftObjectPath MaterialPath = MaterialPack->FindMaterial(ShaderName, MaterialType);
				if (MaterialPath.IsValid() && !MaterialPath.IsNull())
				{
					return MaterialPath;
				}
			}
		}

		// Hard code the old settings.  This could be done via a built in pack instead, but would need to be made in 4.25.
		if (MaterialType == EDazMaterialType::Base)
		{
			if (ShaderName.Compare(TEXT("Daz Studio Default")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/DSDBaseMaterial.DSDBaseMaterial"));
			if (ShaderName.Compare(TEXT("omUberSurface")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/omUberBaseMaterial.omUberBaseMaterial"));
			if (ShaderName.Compare(TEXT("AoA_Subsurface")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/AoASubsurfaceBaseMaterial.AoASubsurfaceBaseMaterial"));
			if (ShaderName.Compare(TEXT("Iray Uber")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/IrayUberBaseMaterial.IrayUberBaseMaterial"));
			if (ShaderName.Compare(TEXT("PBRSkin")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/BasePBRSkinMaterial.BasePBRSkinMaterial"));
		}

		if (MaterialType == EDazMaterialType::Skin)
		{
			if (ShaderName.Compare(TEXT("Daz Studio Default")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/DSDBaseMaterial.DSDBaseMaterial"));
			if (ShaderName.Compare(TEXT("omUberSurface")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/omUberSkinMaterial.omUberSkinMaterial"));
			if (ShaderName.Compare(TEXT("AoA_Subsurface")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/AoASubsurfaceSkinMaterial.AoASubsurfaceSkinMaterial"));
			if (ShaderName.Compare(TEXT("Iray Uber")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/IrayUberSkinMaterial.IrayUberSkinMaterial"));
			if (ShaderName.Compare(TEXT("PBRSkin")) == 0) return FSoftObjectPath(TEXT("/DazToUnreal/BasePBRSkinMaterial.BasePBRSkinMaterial"));
		}

		if(MaterialType == EDazMaterialType::Base) return FSoftObjectPath(TEXT("/DazToUnreal/BaseMaterial.BaseMaterial"));
		if (MaterialType == EDazMaterialType::Alpha) return FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		if (MaterialType == EDazMaterialType::Masked) return FSoftObjectPath(TEXT("/DazToUnreal/BaseMaskedMaterial.BaseMaskedMaterial"));
		if (MaterialType == EDazMaterialType::Skin) return FSoftObjectPath(TEXT("/DazToUnreal/BaseSSSSkinMaterial.BaseSSSSkinMaterial"));
		if (MaterialType == EDazMaterialType::Hair) return FSoftObjectPath(TEXT("/DazToUnreal/BaseHairMaterial.BaseHairMaterial"));
		if (MaterialType == EDazMaterialType::Scalp) return FSoftObjectPath(TEXT("/DazToUnreal/BaseScalpMaterial.BaseScalpMaterial"));
		if (MaterialType == EDazMaterialType::EyeMoisture) return FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		if (MaterialType == EDazMaterialType::Cornea) return FSoftObjectPath(TEXT("/DazToUnreal/BaseAlphaMaterial.BaseAlphaMaterial"));
		if (MaterialType == EDazMaterialType::NoDraw) return FSoftObjectPath(TEXT("/DazToUnreal/NoDrawMaterial.NoDrawMaterial"));

		// Fall back to a known default if nothing else was found.
		return FSoftObjectPath(TEXT("/DazToUnreal/BaseMaterial.BaseMaterial"));
	}
};