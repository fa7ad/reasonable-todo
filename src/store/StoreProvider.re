open StoreContext;

module Store = {
  let make = React.Context.provider(storeCtx);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};

module Dispatch = {
  let make = React.Context.provider(dispatchCtx);

  let makeProps = (~value, ~children, ()) => {
    "value": value,
    "children": children,
  };
};