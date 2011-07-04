#include "GobjectImplStringTopNode.hpp"
#include "GobjectImplError.hpp"
#include "GobjectImplNode.hpp"
#include "GobjectImplScalar.hpp"
namespace jsonme {
  namespace impl {
     GobjectImplStringTopNode::GobjectImplStringTopNode(std::string jsonstring):mRoot(0) {
       GobjectImplError lerror;
       json_parser_load_from_data (mParser,jsonstring.c_str(),jsonstring.size(),lerror.errorp());
       if (lerror.error()) {
          throw jsonme::ParseError(lerror.error()->message);
       }
       mRoot=new GobjectImplNode(json_parser_get_root(mParser));
     } 
     GobjectImplStringTopNode::~GobjectImplStringTopNode() {
       delete mRoot;
     }
     jsonme::nodetype GobjectImplStringTopNode::nodetype() {
        return mRoot->nodetype();
     }
     Node GobjectImplStringTopNode::operator[](std::string name) {
        return (*mRoot)[name];
     }
     size_t GobjectImplStringTopNode::size() {
        return mRoot->size();
     }
     Node GobjectImplStringTopNode::operator[](size_t index) {
        return (*mRoot)[index];
     }
     GobjectImplStringTopNode::operator Scalar() {
        return (*mRoot);
     }
  }
}