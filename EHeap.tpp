#pragma once

template<typename T>
class EHeap
{
    private:
        class HandleData
        {
            friend EHeap;
            private:
                int index;
                /* Private fields & methods to be completed by you. */
            public:
                HandleData() : index(1) {}
                HandleData(int userIndex) : index(userIndex+1) {}
        };

        const unsigned mCapacity;
        unsigned mSize;
        T *mHeap;
        HandleData *mHandle;
        /* Private fields & methods to be completed by you. */

    public:
        typedef HandleData * Handle;

        EHeap(unsigned capacity) : mCapacity(capacity),
                                    mSize(0),
                                    mHeap(new T[capacity + 1]),
                                    mHandle(new HandleData[capacity + 1])
{}

        unsigned size() const { return this->mSize; }

        void percolateUp(unsigned i)
        {
            while (i > 1 and mHeap[i / 2] > mHeap[i])
            {
                std::swap(mHeap[i / 2], mHeap[i]);
                i = i / 2;
                
            }
        }

        Handle push(T t) { 
                mSize++;
                mHeap[mSize] = t;
                this->mHandle->index = mSize-1;
                int i=mSize;
                while (i > 1 and mHeap[i / 2] > mHeap[i])
                {
                    std::swap(mHeap[i / 2], mHeap[i]);
                    i = i / 2;
                    this->mHandle->index = i;
                }       
                return this->mHandle;
                
}

        T pop() {
            T popped = mHeap[1];
            std::swap(mHeap[1], mHeap[mSize]);
            mSize--;
            unsigned i=1;
            while (2 * i <= mSize)
            {
                unsigned minChild;

                if (2 * i + 1 <= mSize and mHeap[2 * i + 1] < mHeap[2 * i])
                {
                    minChild = 2 * i + 1;
                }
                else
                {
                    minChild = 2 * i;
                }

                if (mHeap[minChild] < mHeap[i])
                {
                    std::swap(mHeap[minChild], mHeap[i]);
                    i = minChild;
                }
                else
                {
                    break;
                }
            }

            return popped;

}

        T erase(Handle handle) {
  
            std::swap(mHeap[handle->index],mHeap[mSize+1]);
              unsigned int i;
            i=handle->index;
            while (2 * i < mSize)
            {
                unsigned minChild;

                if (2 * i + 1 <= mSize and mHeap[2 * i + 1] < mHeap[2 * i])
                {
                    minChild = 2 * i + 1;
                }
                else
                {
                    minChild = 2 * i;
                }

                if (mHeap[minChild] < mHeap[i])
                {
                    std::swap(mHeap[minChild], mHeap[i]);
                    i = minChild;
                }
                else
                {
                    break;
                }
            }            
        }


        ~EHeap() { delete [] mHeap;
                    delete [] mHandle;
                    }
};
