class event_list():
    """Dictionary of Event Offset Numbers and AET EVENT Names from AET LIB"""

    mem_events = {
        0:  ' 0: AET_EVT_MEM_L1D_RH_SRAM_A',
        1:  ' 1: AET_EVT_MEM_L1D_RH_SRAM_B',
        2:  ' 2: AET_EVT_MEM_L1D_RH_CACHE_A',
        3:  ' 3: AET_EVT_MEM_L1D_RH_CACHE_B',
        4:  ' 4: AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_A',
        5:  ' 5: AET_EVT_MEM_L1D_WH_BUF_NOT_FULL_B',
        6:  ' 6: AET_EVT_MEM_L1D_WH_BUF_FULL_A',
        7:  ' 7: AET_EVT_MEM_L1D_WH_BUF_FULL_B',
        8:  ' 8: AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_A',
        9:  ' 9: AET_EVT_MEM_L1D_RM_HITS_L2_SRAM_B',
        10: '10: AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_A',
        11: '11: AET_EVT_MEM_L1D_RM_HITS_L2_CACHE_B',
        12: '12: AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_A',
        13: '13: AET_EVT_MEM_L1D_RM_HITS_EXT_CABLE_B',
        14: '14: AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_A',
        15: '15: AET_EVT_MEM_L1D_RM_HITS_EXT_NON_CABLE_B',
        16: '16: AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_A',
        17: '17: AET_EVT_MEM_L1D_WM_WRT_BUF_NOT_FULL_B',
        18: '18: AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_A',
        19: '19: AET_EVT_MEM_L1D_WM_WRT_BUF_FULL_B',
        20: '20: AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_A',
        21: '21: AET_EVT_MEM_L1D_WM_TAG_VIC_WRT_BUF_FLUSH_B',
        22: '22: AET_EVT_MEM_CPU_CPU_BANK_CONFLICT',
        23: '23: AET_EVT_MEM_CPU_SNOOP_CONFLICT',
        24: '24: AET_EVT_MEM_CPU_IDMA_EDMA_BANK_CONFLICT',
        25: '25: AET_EVT_MEM_L1P_RH_SRAM',
        26: '26: AET_EVT_MEM_L1P_RH_CACHE',
        27: '27: AET_EVT_MEM_L1P_RM_HITS_L2_SRAM',
        28: '28: AET_EVT_MEM_L1P_RM_HITS_L2_CACHE',
        29: '29: AET_EVT_MEM_L1P_RM_HITS_EXT_CABLE'
    }

    stall_events = {
        0:  ' 0: AET_EVT_STALL_CPU_PIPELINE',
        1:  ' 1: AET_EVT_STALL_CROSS_PATH',
        2:  ' 2: AET_EVT_STALL_BRANCH_TO_SPAN_EXEC_PKT',
        3:  ' 3: AET_EVT_STALL_EXT_FUNC_IFACE',
        4:  ' 4: AET_EVT_STALL_MVC',
        5:  ' 5: AET_EVT_STALL_L1P_OTHER',
        6:  ' 6: AET_EVT_STALL_L1P_WAIT_STATE',
        8:  ' 8: AET_EVT_STALL_L1P_MISS',
        10: '10: AET_EVT_STALL_L1D_OTHER',
        11: '11: AET_EVT_STALL_L1D_BANK_CONFLICT',
        12: '12: AET_EVT_STALL_L1D_DMA_CONFLICT',
        13: '13: AET_EVT_STALL_L1D_WRITE_BUFFER_FULL',
        14: '14: AET_EVT_STALL_L1D_TAG_UD_BUF_FULL',
        15: '15: AET_EVT_STALL_L1D_LINE_FILL_B',
        16: '16: AET_EVT_STALL_L1D_LINE_FILL_A',
        17: '17: AET_EVT_STALL_L1D_WRT_BUF_FLUSH',
        18: '18: AET_EVT_STALL_L1D_VICTIM_BUF_FLUSH',
        20: '20: AET_EVT_STALL_L1D_TAG_UD_BUF_FLUSH',
        21: '21: AET_EVT_STALL_L1D_SNOOP_CONFLICT',
        22: '22: AET_EVT_STALL_L1D_COH_OP_CONFLICT',
    }
