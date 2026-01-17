#ifndef __AML_PSDK_GTALISTS_H
#define __AML_PSDK_GTALISTS_H

struct CPtrNode
{
    void *m_pVoid;
    CPtrNode *m_pNext;
};

struct CPtrNodeSingleLink : CPtrNode
{
};

struct CPtrNodeDoubleLink : CPtrNode
{
    CPtrNodeDoubleLink *m_pPrevious;
};

struct CPtrList
{
    CPtrNode *m_pHead;
};

struct CPtrListDoubleLink : CPtrList
{
};

struct CPtrListSingleLink : CPtrList
{
};

struct CSector
{
    CPtrListSingleLink m_buildingPtrListArray;
    CPtrListDoubleLink m_dummyPtrListArray;
};

struct CRepeatSector
{
    CPtrListDoubleLink m_ptrListArray[3];
};

struct CEntryInfoNode
{
    CPtrListDoubleLink *m_pList;
    CPtrNodeDoubleLink *m_pNode;
    union
    {
        CSector *m_pStandardSector;
        CRepeatSector *m_pRepeatSector;
    };
    CEntryInfoNode *m_pPrevious;
    CEntryInfoNode *m_pNext;
};

struct CEntryInfoList
{
    CEntryInfoNode *m_pHead;
};

#endif