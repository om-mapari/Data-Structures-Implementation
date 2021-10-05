void Tbt ::Delete(int data)
{
    Tbtnode *temp = root->left, *p = root;
    for (;;)
    {
        if (temp->data < data)
        {
            /* not found */
            if (temp->rightThread)
                return;
            p = temp;
            temp = temp->right;
        }
        else if (temp->data > data)
        {
            /* not found */
            if (temp->leftThread)
                return;
            p = temp;
            temp = temp->left;
        }
        else
        {
            /* found */
            break;
        }
    }
    Tbtnode *target = temp;
    if (!temp->rightThread && !temp->leftThread)
    {
        /* temp has two children*/
        p = temp;
        /* find largest Tbtnode at left child */
        target = temp->left;
        while (!target->rightThread)
        {
            p = target;
            target = target->right;
        }
        /* using replace mode*/
        temp->data = target->data;
    }
    if (p->data >= target->data)
    {
        if (target->rightThread && target->leftThread)
        {
            p->left = target->left;
            p->leftThread = true;
        }
        else if (target->rightThread)
        {
            Tbtnode *largest = target->left;
            while (!largest->rightThread)
            {
                largest = largest->right;
            }
            largest->right = p;
            p->left = target->left;
        }
        else
        {
            Tbtnode *smallest = target->right;
            while (!smallest->leftThread)
            {
                smallest = smallest->left;
            }
            smallest->left = target->left;
            p->left = target->right;
        }
    }
    else
    {
        if (target->rightThread && target->leftThread)
        {
            p->right = target->right;
            p->rightThread = true;
        }
        else if (target->rightThread)
        {
            Tbtnode *largest = target->left;
            while (!largest->rightThread)
            {
                largest = largest->right;
            }
            largest->right = target->right;
            p->right = target->left;
        }
        else
        {
            Tbtnode *smallest = target->right;
            while (!smallest->leftThread)
            {
                smallest = smallest->left;
            }
            smallest->left = p;
            p->right = target->right;
        }
    }
}
