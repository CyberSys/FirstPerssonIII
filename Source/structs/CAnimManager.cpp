/*
Plugin-SDK (Grand Theft Auto) source file
Authors: GTA Community. See more here
https://github.com/DK22Pac/plugin-sdk
Do not delete this comment block. Respect others' work!
*/
#include "CAnimManager.h"


CAnimationStyleDescriptor *CAnimManager::ms_aAnimAssocDefinitions = (CAnimationStyleDescriptor*)0x5EB724;
CAnimBlock *CAnimManager::ms_aAnimBlocks = (CAnimBlock*)0x6F01A0;
CAnimBlendHierarchy *CAnimManager::ms_aAnimations = (CAnimBlendHierarchy*)0x70F430;
int &CAnimManager::ms_numAnimBlocks = *(int*)0x885AF8;
int &CAnimManager::ms_numAnimations = *(int*)0x8E2DD4;
CAnimBlendAssocGroup *&CAnimManager::ms_aAnimAssocGroups = *reinterpret_cast<CAnimBlendAssocGroup**>(GLOBAL_ADDRESS_BY_VERSION(0x8F583C, 0x8F58F0, 0));//*(CAnimBlendAssocGroup**)0x8F583C;
CLinkList<CAnimBlendHierarchy*> &CAnimManager::ms_animCache = *(CLinkList<CAnimBlendHierarchy*>*)0x9414DC;

CAnimBlock *CAnimManager::GetAnimationBlock(const char *name)
{
    return plugin::CallAndReturn<CAnimBlock*, 0x4034A0, char const*>(name);
}

CAnimBlendHierarchy * CAnimManager::GetAnimation(const char * name, CAnimBlock * animBlock)
{
	return plugin::CallAndReturn<CAnimBlendHierarchy*, 0x4034F0, const char*, CAnimBlock*>(name, animBlock);
}

CAnimBlendAssociation *CAnimManager::GetAnimAssociation(int AssocGroupId, int AnimationId)
{
    return plugin::CallAndReturn<CAnimBlendAssociation*, 0x4035E0, int, int>(AssocGroupId, AnimationId);
}

CAnimBlendAssociation * CAnimManager::AddAnimation(RpClump * clump, int AssocGroupId, int AnimationId)
{
	return plugin::CallAndReturn<CAnimBlendAssociation*, 0x403620, RpClump*, int, int>(clump, AssocGroupId, AnimationId);
}

CAnimBlendAssociation *CAnimManager::BlendAnimation(RpClump *clump, int AssocGroupId, int AnimationId, float clumpAssocBlendData)
{
    return plugin::CallAndReturn<CAnimBlendAssociation*, 0x403710, RpClump*, int, int, float>(clump, AssocGroupId, AnimationId, clumpAssocBlendData);
}

void CAnimManager::LoadAnimFile(const char * ifp)
{
	plugin::Call<0x403A10, const char*>(ifp);
}
