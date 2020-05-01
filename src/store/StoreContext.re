type ui =
  | Black
  | Color(string);

type uiActions =
  | GoBlack
  | GoColor(string);

type state = {ui};
type dispatch = uiActions => unit;

let initStore: state = {ui: Black};
let storeCtx = React.createContext(initStore);

let initDispatch = _ => ignore();
let dispatchCtx: React.Context.t(dispatch) = React.createContext(initDispatch);

let useStore = () => React.useContext(storeCtx);
let useDispatch = () => React.useContext(dispatchCtx);

let reducer = (_state, action) =>
  switch action {
  | GoBlack => {ui: Black}
  | GoColor(color) => {ui: Color(color)}
  };