# Problem Statement
Implement a Cache which can use both LFU and LRU eviction policies based on specification during initialisation.

# Functional Requirements
- User must be able to select between LFU and LRU cache eviction policy during initialisation for **specified constant cache size**.
- User must be able to insert an element in the cache.
- User must be able to retrieve an element from the cache if available.
- Both the insertion and retrieval must be in $o(1)$ Time Complexity.

# Classes/Interfaces
- Interface `I_Cache`: A common implementation point for any Cache Type.
- Class `Cache_Factory`: To create cache instances based on cache eviction policy and size.
- Class `LFU_Cache`: Cache based on LFU cache eviction policy.
- Class `LRU_Cache`: Cache based on LRU cache eviction policy.