#ifndef SETINT_RECORD
#define SETINT_RECORD

#include "transaction.h"
#include "logrecord.h"
#include "block.h"
#include "logmanager.h"
#include <vector>

class SetIntRecord : LogRecord
{    
    private: 
        int tsx_no;
        int offset;
        int value;
        Block block;
    public: 
        SetIntRecord(Page p);

        Operation op() override;

        int transaction_no() override;

        void undo(Transaction transaction) override; 
        
        std::string to_string();

        static int write_to_log(LogManager& lm, int transaction_no, Block block, int offset, int val);
};

#endif