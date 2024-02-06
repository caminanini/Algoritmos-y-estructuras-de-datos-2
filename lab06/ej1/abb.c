#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};
/*struct _s_abb {
    abb_elem elem;
    abb *left;
    abb *right;
};*/

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool invrep(abb tree) {
    bool res = true;
    if (tree != NULL) {
        if (tree->right != NULL) {
            res = res && !elem_eq(tree->elem, tree->right->elem);
            res = res && elem_less(tree->elem, tree->right->elem);
        }
        if (tree->left != NULL) {
            res = res && !elem_eq(tree->left->elem, tree->elem);
            res = res && elem_less(tree->left->elem, tree->elem);
        }
        // Verificación recursiva para los subárboles izquierdo y derecho
        res = res && invrep(tree->left);
        res = res && invrep(tree->right);
    }
    return res;
}

abb abb_empty(void) {
    abb tree=NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb add = malloc(sizeof(struct _s_abb)); //Se puede hacer todo dentro del primer caso
    add->elem=e;
    add->left=NULL;
    add->right=NULL;
    if(tree==NULL){
        return add;
    }
    else{
        if(elem_less(tree->elem, e)){
            tree->right=abb_add(tree->right,e);
        }
        else if(elem_less(e,tree->elem)){
            tree->left=abb_add(tree->left,e);
        }
    }
    assert(invrep(tree) && abb_exists(tree, e));
    return tree;
}

bool abb_is_empty(abb tree) {
   assert(invrep(tree));
    return tree==NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    assert(invrep(tree));
    bool exists = false;
    if (tree != NULL) {
        if (tree->elem == e) {
            exists = true;
        } else if (tree->elem < e) {
            exists = abb_exists(tree->right, e);
        } else if (tree->elem > e) {
            exists = abb_exists(tree->left, e);
        }
    }
    return exists;
}
/*
bool abb_exists(abb tree, abb_elem e) {
    assert(invrep(tree));
    bool exists = tree!=NULL;
    exists=exists && elem_eq(tree->elem,e)||
    elem_less(e,tree->elem) && abb_exists(tree->left,e)||
    elem_less(tree->elem,e) && abb_exists(tree->right,e)
    return exists;
}
*/


 //Uso una fun auxiliar para mejorar la comprensión
abb_elem maximoaux (abb_elem a,abb_elem b){
    abb_elem res;
    if(a<b){
        res=b;
    }
    else{
        res=a;
    }
    return res;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    //Completar
    if(tree!=NULL){
        length=maximoaux(abb_length(tree->left),abb_length(tree->right))+1;
    }
    assert(invrep(tree) && (abb_is_empty(tree) || length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    // Referencia al puntero que enlaza al nodo a borrar
    struct _s_abb **ref = NULL;
    // Referencia al puntero que enlaza al nodo que reemplazara al borrado
    struct _s_abb **refrepl;
    // Variable auxiliar para las busquedas
    struct _s_abb *curr;
    bool keepLooking = true;
    
    if(tree != NULL) {
        curr = tree;
        /* Busco el elemento a borrar y una referencia al puntero que lo enlaza */
        while(keepLooking) {
            if(elem_less(e, curr -> elem)) {
            ref = &curr -> left;
            curr = curr -> left; 
            }
            else if(elem_less(curr -> elem, e)) {
            ref = &curr -> right;
            curr = curr -> right; 
            } else {
            keepLooking = false;
            }
        }
        if(ref == NULL) {
            ref = &tree;
        }

        /* PRE: 
        * curr = elemento a borrar && 
        * ref  = referencia al puntero que apunta al lugar del elemento borrado
        */

        /* Busco el minimo nodo del arbol de la derecha */
        refrepl = &curr -> right;
        curr = curr -> right;
        if(curr != NULL) {

            while(curr -> left != NULL) {
            refrepl = &curr -> left;
            curr = curr -> left;
            }
            // Quitamos el reemplazo del lugar en el que esta
            *refrepl = curr -> right;
        }
        /* PRE
        * curr = minimo nodo del arbol de la derecha 
        * */
        
        /* Ubico el reemplazo en el lugar del nodo borrado
        * y libero la memoria del nodo a borrar usando la ref 
        */
        if(curr != NULL) {
            curr -> left = (*ref) -> left;
            curr -> right = (*ref) -> right;
        } 
        else {
            /* Si el right es nulo, entonces solo tenemos que poner el 
            * izquierdo en el lugar del borrado.
            * */
            curr = (*ref) -> left;
        }
        
        if(*ref != NULL) {
            free(*ref);
        }

        *ref = curr;
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}
/*
abb abb_remove(abb tree,abb_elem e){
 abb auxtree1,auxtree2;
 if(tree!=NULL){
 if(tree->elem>e){
    trr->left=abb_remove(tree->left,e); 
    }    
    if(tree->elem<e){
        tree->right=abb_remove(tree->right,e)
    }
    if(tree->elem == e){
        if(tree->right==NULL){
            auxtree1=tree->left;
            free(tree);
            tree=auxtree1;
        }
        else{
            auxtree1=tree->right;
            if(auxtree1->left==NULL){
                auxtree1->left=tree->left
                free(tree);
                tree=auxtree1;
            }
            else{
                auxtree2=auxtree1->left;
                while(auxtree2->left!=NULL){
                    auxtree1=auxtree1->left;
                    auxtree2=auxtree2->left;
                }
                auxtree1->left=auxtree2->right;
                tree->elem = auxtree2->elem;
                free(auxtree2);
                auxtree2=NULL;
            }
        }
    }
 }
}
*/

abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root=tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
   if(tree != NULL){
        if(tree->right != NULL){
            max_e=abb_max(tree->left);
        }
        else{
            max_e = tree->elem;
        }
    }

    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if(tree != NULL){
        if(tree->left != NULL){
            min_e=abb_min(tree->left);
        }
        else{
            min_e = tree->elem;
        }
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        //Forma original
        /*abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);*/
        printf("%d ", tree->elem);
        abb_dump(tree->left);
        abb_dump(tree->right);
        }

}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if(tree != NULL){
    abb l=tree->left,r=tree->right;
    free(tree);
    abb_destroy(l);
    abb_destroy(r);
    }
    tree=NULL;
    assert(tree == NULL);
    return tree;
}

