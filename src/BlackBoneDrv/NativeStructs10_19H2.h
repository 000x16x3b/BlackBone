#pragma warning(disable : 4214 4201)
#pragma pack(push, 1)

typedef struct _MM_AVL_NODE
{
    struct _MM_AVL_NODE* LeftChild;
    struct _MM_AVL_NODE* RightChild;

    union ___unnamed1666
    {
        struct
        {
            __int64 Balance : 2;
        };
        struct _MM_AVL_NODE* Parent;
    } u1;
} MM_AVL_NODE, * PMM_AVL_NODE, * PMMADDRESS_NODE;

typedef struct _RTL_AVL_TREE
{
    PMM_AVL_NODE BalancedRoot;
    void* NodeHint;
    unsigned __int64 NumberGenericTableElements;
} RTL_AVL_TREE, * PRTL_AVL_TREE, MM_AVL_TABLE, * PMM_AVL_TABLE;

struct _EX_PUSH_LOCK
{
    union
    {
        struct
        {
            ULONGLONG Locked : 1;                                            
            ULONGLONG Waiting : 1;                                            
            ULONGLONG Waking : 1;                                            
            ULONGLONG MultipleShared : 1;                                    
            ULONGLONG Shared : 60;                                           
        };
        ULONGLONG Value;                                                 
        VOID* Ptr;                                                         
    };
};

struct _MMVAD_FLAGS
{
    ULONG Lock : 1;                                                        
    ULONG LockContended : 1;                                                 
    ULONG DeleteInProgress : 1;                                              
    ULONG NoChange : 1;                                                    
    ULONG VadType : 3;                                                       
    ULONG Protection : 5;                                                  
    ULONG PreferredNode : 6;                                                  
    ULONG PageSize : 2;                                                       
    ULONG PrivateMemory : 1;
};

struct _MMVAD_FLAGS1
{
    ULONG CommitCharge : 31;                                        
    ULONG MemCommit : 1;
};

struct _MMVAD_FLAGS2
{
    ULONG FileOffset : 24;                                                  
    ULONG Large : 1;                                                          
    ULONG TrimBehind : 1;                                               
    ULONG Inherit : 1;                                                        
    ULONG NoValidationNeeded : 1;                                           
    ULONG PrivateDemandZero : 1;                                             
    ULONG Spare : 3;
};

struct _MI_VAD_SEQUENTIAL_INFO
{
    ULONGLONG Length : 12;                                                   
    ULONGLONG Vpn : 52;
};

union ___unnamed1951
{
    unsigned long LongFlags;
    struct _MMVAD_FLAGS VadFlags;
};

union ___unnamed1952
{
    unsigned long LongFlags1;
    struct _MMVAD_FLAGS1 VadFlags1;
};

union ___unnamed2047
{
    unsigned long LongFlags2;
    struct _MMVAD_FLAGS2 VadFlags2;
};

union ___unnamed2048
{
    struct _MI_VAD_SEQUENTIAL_INFO SequentialVa;
    struct _MMEXTEND_INFO* ExtendedInfo;
};

struct _MM_PRIVATE_VAD_FLAGS
{
    ULONG Lock : 1;                                                           
    ULONG LockContended : 1;                                               
    ULONG DeleteInProgress : 1;                                              
    ULONG NoChange : 1;                                                       
    ULONG VadType : 3;                                                    
    ULONG Protection : 5;                                                  
    ULONG PreferredNode : 6;                                                  
    ULONG PageSize : 2;                                                      
    ULONG PrivateMemoryAlwaysSet : 1;                                        
    ULONG WriteWatch : 1;                                                     
    ULONG FixedLargePageSize : 1;                                             
    ULONG ZeroFillPagesOptional : 1;                                       
    ULONG Graphics : 1;                                                      
    ULONG Enclave : 1;                                                    
    ULONG ShadowStack : 1;
};

struct _MM_GRAPHICS_VAD_FLAGS
{
    ULONG Lock : 1;                                                           
    ULONG LockContended : 1;                                                  
    ULONG DeleteInProgress : 1;                                               
    ULONG NoChange : 1;                                                    
    ULONG VadType : 3;                                                      
    ULONG Protection : 5;                                                 
    ULONG PreferredNode : 6;                                                
    ULONG PageSize : 2;                                                    
    ULONG PrivateMemoryAlwaysSet : 1;                                   
    ULONG WriteWatch : 1;                                                  
    ULONG FixedLargePageSize : 1;                                      
    ULONG ZeroFillPagesOptional : 1;                                         
    ULONG GraphicsAlwaysSet : 1;                                            
    ULONG GraphicsUseCoherentBus : 1;                                      
    ULONG GraphicsPageProtection : 3;
};

struct _MM_SHARED_VAD_FLAGS
{
    ULONG Lock : 1;                                                           
    ULONG LockContended : 1;                                               
    ULONG DeleteInProgress : 1;                                            
    ULONG NoChange : 1;                                                     
    ULONG VadType : 3;                                                       
    ULONG Protection : 5;                                                    
    ULONG PreferredNode : 6;                                                
    ULONG PageSize : 2;                                                    
    ULONG PrivateMemoryAlwaysClear : 1;                                      
    ULONG PrivateFixup : 1;                                              
    ULONG HotPatchAllowed : 1;
};

typedef struct _MMVAD_SHORT
{
    union
    {
        struct
        {
            struct _MMVAD_SHORT* NextVad;                                   
            VOID* ExtraCreateInfo;                                         
        };
        struct _RTL_BALANCED_NODE VadNode;                                 
    };
    ULONG StartingVpn;                                                 
    ULONG EndingVpn;                                                      
    UCHAR StartingVpnHigh;                                                 
    UCHAR EndingVpnHigh;                                                
    UCHAR CommitChargeHigh;                                                
    UCHAR SpareNT64VadUChar;                                              
    LONG ReferenceCount;                                                  
    struct _EX_PUSH_LOCK PushLock;                                       
    union
    {
        ULONG LongFlags;                                                    
        struct _MMVAD_FLAGS VadFlags;                                    
        struct _MM_PRIVATE_VAD_FLAGS PrivateVadFlags;                     
        struct _MM_GRAPHICS_VAD_FLAGS GraphicsVadFlags;                     
        struct _MM_SHARED_VAD_FLAGS SharedVadFlags;                       
        volatile ULONG VolatileVadLong;                                  
    } u;                                                                
    union
    {
        ULONG LongFlags1;                                                   
        struct _MMVAD_FLAGS1 VadFlags1;                                   
    } u1;                                                                   
    struct _MI_VAD_EVENT_BLOCK* EventList;
} MMVAD_SHORT, * PMMVAD_SHORT;


typedef struct _MMVAD
{
    struct _MMVAD_SHORT Core;                                              
    union
    {
        ULONG LongFlags2;                                                  
        volatile struct _MMVAD_FLAGS2 VadFlags2;                            
    } u2;                                                                  
    struct _SUBSECTION* Subsection;                                        
    struct _MMPTE* FirstPrototypePte;                                       
    struct _MMPTE* LastContiguousPte;                                      
    struct _LIST_ENTRY ViewLinks;                                          
    struct _EPROCESS* VadsProcess;                                         
    union
    {
        struct _MI_VAD_SEQUENTIAL_INFO SequentialVa;                       
        struct _MMEXTEND_INFO* ExtendedInfo;                               
    } u4;                                                                  
    struct _FILE_OBJECT* FileObject;
} MMVAD, * PMMVAD;
#pragma pack(pop)

typedef struct _HANDLE_TABLE
{
    ULONG NextHandleNeedingPool;
    long ExtraInfoPages;
    LONG_PTR TableCode;
    PEPROCESS QuotaProcess;
    LIST_ENTRY HandleTableList;
    ULONG UniqueProcessId;
    ULONG Flags;
    EX_PUSH_LOCK HandleContentionEvent;
    EX_PUSH_LOCK HandleTableLock;
} HANDLE_TABLE, * PHANDLE_TABLE;

typedef struct _API_SET_VALUE_ENTRY_10
{
    ULONG Flags;
    ULONG NameOffset;
    ULONG NameLength;
    ULONG ValueOffset;
    ULONG ValueLength;
} API_SET_VALUE_ENTRY_10, * PAPI_SET_VALUE_ENTRY_10;

typedef struct _API_SET_VALUE_ARRAY_10
{
    ULONG Flags;
    ULONG NameOffset;
    ULONG Unk;
    ULONG NameLength;
    ULONG DataOffset;
    ULONG Count;
} API_SET_VALUE_ARRAY_10, * PAPI_SET_VALUE_ARRAY_10;

typedef struct _API_SET_NAMESPACE_ENTRY_10
{
    ULONG Limit;
    ULONG Size;
} API_SET_NAMESPACE_ENTRY_10, * PAPI_SET_NAMESPACE_ENTRY_10;

typedef struct _API_SET_NAMESPACE_ARRAY_10
{
    ULONG Version;
    ULONG Size;
    ULONG Flags;
    ULONG Count;
    ULONG Start;
    ULONG End;
    ULONG Unk[2];
} API_SET_NAMESPACE_ARRAY_10, * PAPI_SET_NAMESPACE_ARRAY_10;

#pragma warning(default : 4214 4201)
#define GET_VAD_ROOT(Table) Table->BalancedRoot