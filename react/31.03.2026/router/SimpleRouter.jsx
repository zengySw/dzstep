import React, { createContext, useContext } from 'react';

const RouterContext = createContext({
  path: '/',
  outlet: null,
  loaderData: null,
  isLoading: false,
  loaderError: ''
});

export const RouterProvider = ({ value, children }) => {
  return <RouterContext.Provider value={value}>{children}</RouterContext.Provider>;
};

export const useRouter = () => useContext(RouterContext);

export const Outlet = () => {
  const { outlet } = useRouter();
  return outlet;
};

export const Link = ({ to, className = '', children }) => {
  const { path } = useRouter();
  const normalizedTo = to.startsWith('/') ? to : `/${to}`;
  const isActive = path === normalizedTo;

  return (
    <a
      href={`#${normalizedTo}`}
      className={`${className}${isActive ? ' active' : ''}`}
      aria-current={isActive ? 'page' : undefined}
    >
      {children}
    </a>
  );
};

export const useLoaderData = () => {
  const { loaderData, isLoading, loaderError } = useRouter();
  return { loaderData, isLoading, loaderError };
};
